#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <fstream>
using namespace std;

const int LEN = 36; // 26 + 10
char g_arrCharElem[LEN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                           'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                           'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                           'u', 'v', 'w', 'x', 'y', 'z'
                          };
const char *first_domain[264] = {"/com" , "/edu" , "/gov"  , "/int" , "/mil" , "/net", "/org", "/bank", "/pro", "/biz",
                                 "/info", "/name", "/museum", "/coop", "/aero", "/xxx", "/idv", "/ac",   "/ad",  "/ae",
                                 "/af",   "/ag",   "/ai",    "/al",   "/am",   "/an",  "/ao",  "/aq",   "/ar",  "/as",
                                 "/aw",   "/az",   "/ba",    "/bb",   "/bd",   "/be",  "/bf",  "/bg",   "/bh",  "/bi",
                                 "/bn",   "/bo",   "/br",    "/bs",   "/bt",   "/bv",  "/bw",  "/by",   "/bz",  "/ca",
                                 "/cd",   "/ch",   "/ci",    "/ck",   "/cl",   "/cm",  "/cn",  "/co",   "/cq",  "/cr",
                                 "/cx",   "/cy",   "/cz",    "/de",   "/dj",   "/dk",  "/dm",  "/do",   "/dz",  "/tt",
                                 "/ec",   "/ee",   "/eg",    "/eh",   "/er",   "/es",  "/et",  "/ev",   "/fi",  "/fj",
                                 "/fo",   "/fr",   "/ga",    "/gd",   "/ge",   "/gf",  "/gg",  "/gh",   "/gi",  "/gl",
                                 "/gp",   "/gr",   "/gs",    "/gt",   "/gu",   "/gw",  "/gy",  "/hk",   "/hm",  "/hn",
                                 "/hu",   "/id",   "/ie",    "/il",   "/im",   "/in",  "/at",  "/au",   "/bj",  "/bm",
                                 "/io",   "/iq",   "/ir",    "/is",   "/it",   "/jm",  "/jo",  "/jp",   "/je",  "/ke",
                                 "/ki",   "/km",   "/kn",    "/kp",   "/kr",   "/kw",  "/ky",  "/kz",   "/la",  "/lb",
                                 "/lk",   "/lr",   "/ls",    "/lt",   "/lu",   "/lv",  "/ly",  "/ma",   "/mc",  "/md",
                                 "/mh",   "/mk",   "/ml",    "/mm",   "/mn",   "/mo",  "/cc",  "/cf",   "/cu",  "/cv",
                                 "/mp",   "/mq",   "/mr",    "/ms",   "/mt",   "/mu",  "/mv",  "/mw",   "/mx",  "/my",
                                 "/nc",   "/ne",   "/nf",    "/ng",   "/ni",   "/nl",  "/no",  "/np",   "/nr",  "/nt",
                                 "/om",   "/qa",   "/pa",    "/pe",   "/pf",   "/pg",  "/ph",  "/pk",   "/pl",  "/pm",
                                 "/pt",   "/pw",   "/py",    "/re",   "/rs",   "/ro",  "/fk",  "/fm",   "/gm",  "/gn",
                                 "/ru",   "/rw",   "/sa",    "/sb",   "/sc",   "/sd",  "/se",  "/sg",   "/sh",  "/si",
                                 "/sl",   "/sm",   "/sn",    "/so",   "/sr",   "/st",  "/sv",  "/su",   "/sy",  "/sz",
                                 "/tf",   "/tg",   "/th",    "/tj",   "/tk",   "/tl",  "/tm",  "/tn",   "/to",  "/tr",
                                 "/tw",   "/tz",   "/ua",    "/ug",   "/uk",   "/um",  "/hr",  "/ht",   "/kg",  "/kh",
                                 "/us",   "/uy",   "/uz",    "/va",   "/vc",   "/ve",  "/vg",  "/vi",   "/vn",  "/vu",
                                 "/ye",   "/yt",   "/yu",    "/yr",   "/za",   "/zm",  "/zw",  "/wf",   "/ws",  "/tv",
                                 "/lc",   "/li",   "/tc",    "/td",   "/sj",   "/sk",  "/pn",  "/pr",   "/nu",  "/nz",
                                 "/mz",   "/na",   "/me",    "/mg"
                                };


int main(int argc, char const *argv[])
{
    srand((unsigned)time(0));
    ofstream outfile;
    outfile.open("one.tmp");

    const char* input_number = argv[1];
    int num = atoi(input_number); //the total build number


    for (int i = 0; i < 264; ++i)
    {
        outfile << first_domain[i] << endl;
    }

    for (int i = 264; i < num; i++) {

        int iMax;
        iMax = 1; //the number of components

        for (int i = 0; i < iMax; i++) {
            int iLen;

            iLen = rand() % 4 + 1; //the string's length of each component

            char* szStr = new char[iLen + 1];
            szStr[iLen] = '\0';
            int iRand = 0;
            for (int i = 0; i < iLen; ++i)
            {
                iRand = rand() % LEN;            // iRand = 0 - 35
                szStr[i] = g_arrCharElem[iRand];
            }
            int ido = rand() % 264;
            outfile << first_domain[ido] << szStr;
            delete[] szStr;
        }
        outfile << endl;
    }

    outfile.close();
    return 0;
}
