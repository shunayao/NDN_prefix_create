
//Usage:./deduplication n.tmp n.tmp n.fib

#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>  // gettimeofday
#include "art.h"
#include "art1.c"

static double gettime(void)
{
	struct timeval now_tv;
	gettimeofday (&now_tv, NULL);
	return ((double)now_tv.tv_sec) + ((double)now_tv.tv_usec) / 1000000.0;
}
int main(int argc, char**argv) {
	art_tree t;
	int res = art_tree_init(&t);
	if (res != 0) exit(1);
	printf("init_art_size=%"PRIu64"\n", art_size(&t));
	char *prefix_file_name;
	char *trace_file_name;
	char *output_file_name;

// test_insert
	prefix_file_name = argv[1];
	double start = gettime();
	uintptr_t line = 1;
	int len;
	char buf[512];
	FILE *f0 = fopen(prefix_file_name, "r");
	if (f0 == NULL) {
		printf("error!\n");
		exit(1);
	}
	while (fgets(buf, sizeof buf, f0)) {
		len = strlen(buf);
		line++;
	}
	double  read_file_time = gettime() - start;
	printf("total read file number: %ld , time:  %f\n", line - 1, read_file_time );

//Insert
	rewind(f0);
	start = gettime();
	line = 1;
	output_file_name=argv[3];
	FILE *outfile = fopen(output_file_name, "w");
	while (fgets(buf, sizeof buf, f0))
	{
		len = strlen(buf);
		buf[len - 1] = '\0';
		uintptr_t re = (uintptr_t*)art_insert(&t, (unsigned char*)buf, len, (void*)line);
		if (!re) {
			//printf("the line:%d ,the key:%s\n", line, buf );
			fputs(buf, outfile);
			fputs("\n", outfile);
		}

		line++;

	}
	fclose(f0);
	fclose(outfile);
	printf("total insert number: %ld ,insert line number: %ld , time: %f\n", line - 1, art_size(&t), gettime() - start);

	trace_file_name = argv[2];
	start = gettime();
	FILE *f_trace = fopen(trace_file_name, "r");

// Search
	line = 0;
	int search_line = 0;
	while (fgets(buf, sizeof buf, f_trace))
	{
		len = strlen(buf);
		buf[len - 1] = '\0';
		uintptr_t val = (uintptr_t)art_search(&t, (unsigned char*)buf, len);
		if (val != NULL)
		{
			search_line++;
			//printf("Searched_Line: %d Val: %" PRIuPTR " Str: %s\n", search_line, val, buf);
		}
		line++;
	}
	fclose(f_trace);
	printf("total lookup number: %ld , find  line number: %d , time: %f\n", line, search_line, gettime() - start );

//test_destroy
	res = art_tree_destroy(&t);
	if (res != 0) exit(1);
	printf("destroy_art_size=%"PRIu64"\n", art_size(&t));

	return 0;
}