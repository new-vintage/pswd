
#include <stdio.h>                                                           // i/o printf() scanf()
#include <stdlib.h>                                                        // malloc() atoi() rand()
#include <string.h>                                                              // string functions
#include <ctype.h>                                   // character functions like isdigit() isalpha()
#include <stdbool.h>                                                               // bool variables
#include <time.h>                                                                  // seeding rand()


int help() {                                                                        // START help ()

char answer = '\0';

    printf("\npswd 0.02 password generator\n\n");
    printf("usage: pswd # -h -help -H -U -xu -xs -el# -eu# -en# -es# -l# -u#  -n# -s#\n\n");
    printf("The # represents integers 1-1000\n\n");
    printf("Default password length = 8 using all types of characters\n\n");
    printf("parameter:  #...................................password length: integer 1-1000\n\n");
    printf("switches:  -h OR -help..............print this help (overrides everything else)\n\n");
    printf("           -H..................hexadecimal numbers only, other switches ignored\n");
    printf("           -U.................unshifted characters only, other switches ignored\n\n");
    printf("           -xl..............exclude lower case characters (overrides -el#, -l#)\n");
    printf("           -xu..............exclude upper case characters (overrides -eu#, -u#)\n");
    printf("           -xn.................exclude numeral characters (overrides -en#, -n#)\n");
    printf("           -xs.................exclude special characters (overrides -es#, -s#)\n");
    printf("           -el#..exact number of lower case characters (integer, overrides -l#)\n");
    printf("           -eu#..exact number of upper case characters (integer, overrides -u#)\n");
    printf("           -en#.....exact number of numeral characters (integer, overrides -n#)\n");
    printf("           -es#.....exact number of special characters (integer, overrides -s#)\n");
    printf("           -l#................minimum number of lower case characters (integer)\n");
    printf("           -u#................minimum number of upper case characters (integer)\n");
    printf("           -n#...................minimum number of numeral characters (integer)\n");
    printf("           -s#...................minimum number of special characters (integer)\n\n");
    printf("       Example:  pswd 12 -xu -en5 -s3 generates a 12 character password with no\n");
    printf("               upper case, exactly 5 numerals and at least 3 special characters\n\n");

    while (answer != 'q') {
        printf("Character tables: (a)ll (u)nshifted (h)exadecimal (q)uit (a/u/h/q) ");
        scanf(" %c", &answer);                             // space before  %c  to ignore whitespace

        while (getchar() != '\n');                         // use getchar() to clear input buffer in
                                                           // case 2 or more chars are input by user

        if (answer == 'a') {
            printf("\nALL CHARACTERS\n\n");
            printf("   special   upper case   lower case    numeral\n\n");
            printf(" 1    !           A            a           0\n");
            printf(" 2    \"           B            b           1\n");
            printf(" 3    #           C            c           2\n");
            printf(" 4    $           D            d           3\n");
            printf(" 5    %%           E            e           4\n");
            printf(" 6    &           F            f           5\n");
            printf(" 7    '           G            g           6\n");
            printf(" 8    (           H            h           7\n");
            printf(" 9    )           I            i           8\n");
            printf("10    *           J            j           9               32 special   \n");
            printf("11    +           K            k                           26 upper case\n");
            printf("12    ,           L            l                           26 lower case\n");
            printf("13    -           M            m                           10 numeral\n");
            printf("14    .           N            n\n");
            printf("15    /           O            o                           94 total\n");
            printf("16    :           P            p\n");
            printf("17    ;           Q            q\n");
            printf("18    <           R            r\n");
            printf("19    =           S            s\n");
            printf("20    >           T            t\n");
            printf("21    ?           U            u\n");
            printf("22    @           V            v\n");
            printf("23    [           W            w\n");
            printf("24    \\           X            x\n");
            printf("25    ]           Y            y\n");
            printf("26    ^           Z            z\n");
            printf("27    _\n");
            printf("28    `\n");
            printf("29    {\n");
            printf("30    |\n");
            printf("31    }\n");
            printf("32    ~\n\n");
        }
        if (answer == 'u') {
            printf("\nUNSHIFTED CHARACTERS\n\n");
            printf("   special  lower case   numeral\n\n");
            printf(" 1    `          a          0\n");
            printf(" 2    -          b          1\n");
            printf(" 3    =          c          2\n");
            printf(" 4    [          d          3\n");
            printf(" 5    ]          e          4\n");
            printf(" 6    \\          f          5\n");
            printf(" 7    ;          g          6\n");
            printf(" 8    '          h          7\n");
            printf(" 9    ,          i          8\n");
            printf("10    .          j          9\n");
            printf("11    /          k\n");
            printf("12               l                   11 special\n");
            printf("13               m                   26 lower case\n");
            printf("14               n                   10 numeral\n");
            printf("15               o\n");
            printf("16               p                   47 total\n");
            printf("17               q\n");
            printf("18               r\n");
            printf("19               s\n");
            printf("20               t\n");
            printf("21               u\n");
            printf("22               v\n");
            printf("23               w\n");
            printf("24               x\n");
            printf("25               y\n");
            printf("26               z\n\n");
        }
        if (answer == 'h') {
            printf("\nHEXADECIMAL CHARACTERS\n\n");
            printf("   lower case    numeral\n\n");
            printf(" 1      a           0\n");
            printf(" 2      b           1\n");
            printf(" 3      c           2\n");
            printf(" 4      d           3\n");
            printf(" 5      e           4           6 lower case\n");
            printf(" 6      f           5          10 numerals\n");
            printf(" 7                  6\n");
            printf(" 8                  7          16 total\n");
            printf(" 9                  8\n");
            printf("10                  9\n\n");
        }
    }
    return 0;
}                                                                                      // END help()


char getlower() {                                                                // START getlower()

    char lchar = '\0';                       // tmp char used to store the random char after mapping

    switch (1 + rand() % 26) {
        case 1:
            lchar = 'a';
            break;
        case 2:
            lchar = 'b';
            break;
        case 3:
            lchar = 'c';
            break;
        case 4:
            lchar = 'd';
            break;
        case 5:
            lchar = 'e';
            break;
        case 6:
            lchar = 'f';
            break;
        case 7:
            lchar = 'g';
            break;
        case 8:
            lchar = 'h';
            break;
        case 9:
            lchar = 'i';
            break;
        case 10:
            lchar = 'j';
            break;
        case 11:
            lchar = 'k';
            break;
        case 12:
            lchar = 'l';
            break;
        case 13:
            lchar = 'm';
            break;
        case 14:
            lchar = 'n';
            break;
        case 15:
            lchar = 'o';
            break;
        case 16:
            lchar = 'p';
            break;
        case 17:
            lchar = 'q';
            break;
        case 18:
            lchar = 'r';
            break;
        case 19:
            lchar = 's';
            break;
        case 20:
            lchar = 't';
            break;
        case 21:
            lchar = 'u';
            break;
        case 22:
            lchar = 'v';
            break;
        case 23:
            lchar = 'w';
            break;
        case 24:
            lchar = 'x';
            break;
        case 25:
            lchar = 'y';
            break;
        case 26:
            lchar = 'z';
            break;
    }
    return lchar;
}                                                                                  // END getlower()


char getupper() {                                                                // START getupper()

    char uchar = '\0';                       // tmp char used to store the random char after mapping

    switch (1 + rand() % 26) {
        case 1:
            uchar = 'A';
            break;
        case 2:
            uchar = 'B';
            break;
        case 3:
            uchar = 'C';
            break;
        case 4:
            uchar = 'D';
            break;
        case 5:
            uchar = 'E';
            break;
        case 6:
            uchar = 'F';
            break;
        case 7:
            uchar = 'G';
            break;
        case 8:
            uchar = 'H';
            break;
        case 9:
            uchar = 'I';
            break;
        case 10:
            uchar = 'J';
            break;
        case 11:
            uchar = 'K';
            break;
        case 12:
            uchar = 'L';
            break;
        case 13:
            uchar = 'M';
            break;
        case 14:
            uchar = 'N';
            break;
        case 15:
            uchar = 'O';
            break;
        case 16:
            uchar = 'P';
            break;
        case 17:
            uchar = 'Q';
            break;
        case 18:
            uchar = 'R';
            break;
        case 19:
            uchar = 'S';
            break;
        case 20:
            uchar = 'T';
            break;
        case 21:
            uchar = 'U';
            break;
        case 22:
            uchar = 'V';
            break;
        case 23:
            uchar = 'W';
            break;
        case 24:
            uchar = 'X';
            break;
        case 25:
            uchar = 'Y';
            break;
        case 26:
            uchar = 'Z';
            break;
    }
    return uchar;
}                                                                                  // END getupper()


char getnumeral() {                                                            // START getnumeral()

    char nchar = '\0';                       // tmp char used to store the random char after mapping

    switch (1 + rand() % 10) {
        case 1:
            nchar = '0';
            break;
        case 2:
            nchar = '1';
            break;
        case 3:
            nchar = '2';
            break;
        case 4:
            nchar = '3';
            break;
        case 5:
            nchar = '4';
            break;
        case 6:
            nchar = '5';
            break;
        case 7:
            nchar = '6';
            break;
        case 8:
            nchar = '7';
            break;
        case 9:
            nchar = '8';
            break;
        case 10:
            nchar = '9';
            break;
    }
    return nchar;
}                                                                                // END getnumeral()


char getspecial() {                                                             //START getspecial()

    char schar = '\0';                       // tmp char used to store the random char after mapping

    switch  (1 + rand() % 32) {
        case 1:
            schar = '!';
            break;
        case 2:
            schar = '"';
            break;
        case 3:
            schar = '#';
            break;
        case 4:
            schar = '$';
            break;
        case 5:
            schar = '%';
            break;
        case 6:
            schar = '&';
            break;
        case 7:
            schar = '\'';
            break;
        case 8:
            schar = '(';
            break;
        case 9:
            schar = ')';
            break;
        case 10:
            schar = '*';
            break;
        case 11:
            schar = '+';
            break;
        case 12:
            schar = ',';
            break;
        case 13:
            schar = '-';
            break;
        case 14:
            schar = '.';
            break;
        case 15:
            schar = '/';
            break;
        case 16:
            schar = ':';
            break;
        case 17:
            schar = ';';
            break;
        case 18:
            schar = '<';
            break;
        case 19:
            schar = '=';
            break;
        case 20:
            schar = '>';
            break;
        case 21:
            schar = '?';
            break;
        case 22:
            schar = '@';
            break;
        case 23:
            schar = '[';
            break;
        case 24:
            schar = '\\';
            break;
        case 25:
            schar = ']';
            break;
        case 26:
            schar = '^';
            break;
        case 27:
            schar = '_';
            break;
        case 28:
            schar = '`';
            break;
        case 29:
            schar = '{';
            break;
        case 30:
            schar = '|';
            break;
        case 31:
            schar = '}';
            break;
        case 32:
            schar = '~';
            break;
    }
    return schar;
}                                                                                // END getspecial()

const char* hexmode(int hexstrLength) {                                         // START hexmode()

    char hexchar = '\0';
    static char hexstr[1024] = "";          // static keeps hexstr[] in memory after hexmode() exits
    int i = 0;

    for (i = 0; i < hexstrLength; i++) {
        switch  (1 + rand() % 16) {
            case 1:
                hexchar = '0';
                break;
            case 2:
                hexchar = '1';
                break;
            case 3:
                hexchar = '2';
                break;
            case 4:
                hexchar = '3';
                break;
            case 5:
                hexchar = '4';
                break;
            case 6:
                hexchar = '5';
                break;
            case 7:
                hexchar = '6';
                break;
            case 8:
                hexchar = '7';
                break;
            case 9:
                hexchar = '8';
                break;
            case 10:
                hexchar = '9';
                break;
            case 11:
                hexchar = 'a';
                break;
            case 12:
                hexchar = 'b';
                break;
            case 13:
                hexchar = 'c';
                break;
            case 14:
                hexchar = 'd';
                break;
            case 15:
                hexchar = 'e';
                break;
            case 16:
                hexchar = 'f';
                break;
        }
        strncat(hexstr, &hexchar, 1);
    }
    return hexstr;
}                                                                                   // END hexmode()

const char* unshmode(int unshstrLength) {                                         // START hexmode()

    char unshchar = '\0';
    static char unshstr[1024] = "";       // static keeps unshstr[] in memory after unshmode() exits
    int i = 0;

    for (i = 0; i < unshstrLength; i++) {
        switch  (1 + rand() % 47) {
            case 1:
                unshchar = '`';
                break;
            case 2:
                unshchar = '-';
                break;
            case 3:
                unshchar = '=';
                break;
            case 4:
                unshchar = '[';
                break;
            case 5:
                unshchar = ']';
                break;
            case 6:
                unshchar = '\\';
                break;
            case 7:
                unshchar = ';';
                break;
            case 8:
                unshchar = '\'';
                break;
            case 9:
                unshchar = ',';
                break;
            case 10:
                unshchar = '.';
                break;
            case 11:
                unshchar = '/';
                break;
            case 12:
                unshchar = 'a';
                break;
            case 13:
                unshchar = 'b';
                break;
            case 14:
                unshchar = 'c';
                break;
            case 15:
                unshchar = 'd';
                break;
            case 16:
                unshchar = 'e';
                break;
            case 17:
                unshchar = 'f';
                break;
            case 18:
                unshchar = 'g';
                break;
            case 19:
                unshchar = 'h';
                break;
            case 20:
                unshchar = 'i';
                break;
            case 21:
                unshchar = 'j';
                break;
            case 22:
                unshchar = 'k';
                break;
            case 23:
                unshchar = 'l';
                break;
            case 24:
                unshchar = 'm';
                break;
            case 25:
                unshchar = 'n';
                break;
            case 26:
                unshchar = 'o';
                break;
            case 27:
                unshchar = 'p';
                break;
            case 28:
                unshchar = 'q';
                break;
            case 29:
                unshchar = 'r';
                break;
            case 30:
                unshchar = 's';
                break;
            case 31:
                unshchar = 't';
                break;
            case 32:
                unshchar = 'u';
                break;
            case 33:
                unshchar = 'v';
                break;
            case 34:
                unshchar = 'w';
                break;
            case 35:
                unshchar = 'x';
                break;
            case 36:
                unshchar = 'y';
                break;
            case 37:
                unshchar = 'z';
                break;
            case 38:
                unshchar = '0';
                break;
            case 39:
                unshchar = '1';
                break;
            case 40:
                unshchar = '2';
                break;
            case 41:
                unshchar = '3';
                break;
            case 42:
                unshchar = '4';
                break;
            case 43:
                unshchar = '5';
                break;
            case 44:
                unshchar = '6';
                break;
            case 45:
                unshchar = '7';
                break;
            case 46:
                unshchar = '8';
                break;
            case 47:
                unshchar = '9';
                break;
        }
        strncat(unshstr, &unshchar, 1);
    }

    return unshstr;
}                                                                                  // END unshmode()

const char* scramble (char *str, int strLength) {                           // START scramble()

    int i = 0, j = 0;
    char tmp = '\0';

    for (i = 0; i < strLength; i++) {
        int j = rand() % strLength;
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    return str;
}
                                                                                   // END scramble()

int main (int argc, char *argv[]) {                                                  // START main()

    struct timespec ts;                                     // lines 683-686 are for high resolution
    clock_gettime(CLOCK_MONOTONIC, &ts);                    // (nanosecond)  seeding  of  the rand()
    unsigned long seed = ts.tv_sec ^ ts.tv_nsec;            // function   in   case   this   program
    srand(seed);                                            // runs   multiple   times   per  second

    int PasswordLength = 8;                                           // default password length = 8
    int elnum = 0, eunum = 0, ennum = 0, esnum = 0;                      // exact characters numbers
    int lnum = 0, unum = 0, nnum = 0, snum = 0;                        // minimum characters numbers
    int i = 0, j = 0, k = 0;                           // tmp ints for loop counters, character type
    int fillnumber = 0;                                 // used to fill if password < PasswordLength

    bool xl = false, xu = false, xn = false, xs = false;                            // exclude bools
    bool el = false, eu = false, en = false, es = false;                        // exact count bools

    char tmpchar = '\0';   // captures chars from getlower(), getupper(), getnumeral(), getspecial()
    char tmpstr[10] = "";                                        // tmp string for decoding switches
    char pswd[1024] = "";                                                      // generated password

    const char * returnedStr = "";         // tmp string captures strings from hexmode(), unshmode()

    for (i = 1; i < argc; i++) {                                     // START check for help request
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-help") == 0) {
            help();
            return (EXIT_SUCCESS);
        }
    }                                                                  // END check for help request

    if (argc == 1) {                                                         // START if (argc == 1)
        printf("pswd: default: %d characters, all character types (pswd -h for help)\n", PasswordLength);
    }                                                                          // END if (argc == 1)

    if (argc == 2) {                                                         // START if (argc == 2)
        PasswordLength = atoi(argv[1]);
        if (PasswordLength <= 0 || PasswordLength > 1000) {
            printf("pswd: first parameter: integer 1-1000 (pswd -h for help)\n");
            return (EXIT_FAILURE);
        }                                                // END if (argc == 2) password length check
    }                                                                          // END if (argc == 2)

    if (argc > 2) {                                                           // START if (argc > 2)
        PasswordLength = atoi(argv[1]);
        if (PasswordLength <= 0 || PasswordLength > 1000) {
            printf("pswd: first parameter: integer 1-1000 (pswd -h for help)\n");
            return (EXIT_FAILURE);
        }                                                 // END if (argc > 2) password length check

        for (i = 2; i < argc; i++) {
            if (argv[i][0] != '-') {
                printf("pswd: switches require a leading dash)\n");
                return (EXIT_FAILURE);
            }                                                         // END if (argc > 2 dash check
        }

        for (i = 2; i < argc; i++) {  // START if (argc > 2) hexmode, unshmode, unknown switch check
            if (strcmp(argv[i], "-H") == 0) {
                returnedStr = hexmode(PasswordLength);
                strcpy(pswd, returnedStr);
                printf("%s\n", pswd);
                return (EXIT_SUCCESS);
            }
            if (strcmp(argv[i], "-U") == 0) {
                returnedStr = unshmode(PasswordLength);
                strcpy(pswd, returnedStr);
                printf("%s\n", pswd);
                return (EXIT_SUCCESS);
            }
            if (argv[i][1] == 'x') {
                if (argv[i][2] != 'l' && argv[i][2] != 'u' && argv[i][2] != 'n' && argv[i][2] != 's') {
                    printf("pswd: unknown switch %s\n", argv[i]);
                    return (EXIT_FAILURE);
                }
                if (isalnum(argv[i][3])) {
                    printf("pswd: unknown switch %s\n", argv[i]);
                    return (EXIT_FAILURE);
                }
            }
            if (argv[i][1] == 'e') {
                if (argv[i][2] != 'l' && argv[i][2] != 'u' && argv[i][2] != 'n' && argv[i][2] != 's') {
                    printf("pswd: unknown switch %s\n", argv[i]);
                    return (EXIT_FAILURE);
                }
                if (isdigit(argv[i][3]) == 0) {
                    printf("pswd: -el, -eu, -en, -es switches require an integer %s\n", argv[i]);
                    return (EXIT_FAILURE);
                }
            }
            if (argv[i][1] != 'x' && argv[i][1] != 'e' && argv[i][1] != 'l' && argv[i][1] != 'u' && argv[i][1] != 'n' && argv[i][1] != 's') {
                printf("pswd: unknown switch %s\n", argv[i]);
                return (EXIT_FAILURE);
            }
            if (argv[i][1] == 'l') {
                if (isdigit(argv[i][2]) == 0) {
                    printf("pswd: -l, -u, -n, -s switches require an integer %s\n", argv[i]);
                    return (EXIT_FAILURE);
                }
            }
            if (argv[i][1] == 'u') {
                if (isdigit(argv[i][2]) == 0) {
                    printf("pswd: -l, -u, -n, -s switches require an integer %s\n", argv[i]);
                    return (EXIT_FAILURE);
                }
            }
            if (argv[i][1] == 'n') {
                if (isdigit(argv[i][2]) == 0) {
                    printf("pswd: -l, -u, -n, -s switches require an integer %s\n", argv[i]);
                    return (EXIT_FAILURE);
                }
            }
            if (argv[i][1] == 's') {
                if (isdigit(argv[i][2]) == 0) {
                    printf("pswd: -l, -u, -n, -s switches require an integer %s\n", argv[i]);
                    return (EXIT_FAILURE);
                }
            }
        }                               // END if (argc > 2) hexmode, unshmode, unknown switch check


        for (i = 2; i < argc; i++) {                        // START if (argc > 2) decoding switches
            memset(tmpstr, 0, sizeof(tmpstr));                   // clear tmpstr each loop iteration

//            if (strcmp(argv[i], "-xr") == 0) {                         // something for the future
//                xr = true;
//            }

            if (strcmp(argv[i], "-xl") == 0) {    // START setting bools, decoding -e* -luns numbers
                xl = true;
            }
            if (strcmp(argv[i], "-xu") == 0) {
                xu = true;
            }
            if (strcmp(argv[i], "-xn") == 0) {
                xn = true;
            }
            if (strcmp(argv[i], "-xs") == 0) {
                xs = true;
            }
            if (xl ==false && argv[i][1] == 'e' && argv[i][2] == 'l') {
                el = true;
                for (j = 3; argv[i][j] != '\0'; j++) {
                    strncat(tmpstr, &argv[i][j], 1);
                }
                elnum = atoi(tmpstr);
            }
            if (xu == false && argv[i][1] == 'e' && argv[i][2] == 'u') {
                eu = true;
                for (j = 3; argv[i][j] != '\0'; j++) {
                    strncat(tmpstr, &argv[i][j], 1);
                }
                eunum = atoi(tmpstr);
            }
            if (xn ==false && argv[i][1] == 'e' && argv[i][2] == 'n') {
                en = true;
                for (j = 3; argv[i][j] != '\0'; j++) {
                    strncat(tmpstr, &argv[i][j], 1);
                }
                ennum = atoi(tmpstr);
            }
            if (xs == false && argv[i][1] == 'e' && argv[i][2] == 's') {
                es = true;
                for (j = 3; argv[i][j] != '\0'; j++) {
                    strncat(tmpstr, &argv[i][j], 1);
                }
                esnum = atoi(tmpstr);
            }
            if (xl == false && el == false && argv[i][1] == 'l' && isdigit(argv[i][2])) {
                for (j = 2; argv[i][j] != '\0'; j++) {
                    strncat(tmpstr, &argv[i][j], 1);
                }
                lnum = atoi(tmpstr);
            }
            if (xu == false && eu == false && argv[i][1] == 'u' && isdigit(argv[i][2])) {
                for (j = 2; argv[i][j] != '\0'; j++) {
                    strncat(tmpstr, &argv[i][j], 1);
                }
                unum = atoi(tmpstr);
            }
            if (xn == false && en == false && argv[i][1] == 'n' && isdigit(argv[i][2])) {
                for (j = 2; argv[i][j] != '\0'; j++) {
                    strncat(tmpstr, &argv[i][j], 1);
                }
                nnum = atoi(tmpstr);
            }
            if (xs == false && es == false && argv[i][1] == 's' && isdigit(argv[i][2])) {
                for (j = 2; argv[i][j] != '\0'; j++) {
                    strncat(tmpstr, &argv[i][j], 1);
                }
                snum = atoi(tmpstr);
            }
        }                                           // END setting bools, decoding -e* -luns numbers

        if (xl == true && xu == true && xn == true && xs == true) {                   // error check
            printf("pswd: all character types have been excluded\n");
            return (EXIT_FAILURE);
        }
    }                                                                           // END if (argc > 2)

                                     // START generate characters according to -x -e* -luns switches

    i = elnum + eunum + ennum + esnum + lnum + unum + nnum + snum;                    // error check
    if (i > PasswordLength) {
            printf("pswd: exact or minimum numbers in switches > password length\n");
            return (EXIT_FAILURE);
    }

    if (xl ==  false && xu == false && xn == false && xs == false) {          // START no exclusions
        if (elnum) {
            for (i = 0; i < elnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (eunum) {
            for (i = 0; i < eunum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (ennum) {
            for (i = 0; i < ennum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (esnum) {
            for (i = 0; i < esnum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (lnum) {
            for (i = 0; i < lnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (unum) {
            for (i = 0; i < unum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (nnum) {
            for (i = 0; i < nnum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (snum) {
            for (i = 0; i < snum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (elnum == 0 && eunum == 0 && ennum == 0 && esnum == 0) {       // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 4) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getupper();
                        break;
                    case 2:
                        tmpchar = getnumeral();
                        break;
                    case 3:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && eunum == 0 && ennum == 0 && esnum == 0) {      // 1
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 3) {
                    case 0:
                        tmpchar = getupper();
                        break;
                    case 1:
                        tmpchar = getnumeral();
                        break;
                    case 2:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (eunum) && ennum == 0 && esnum == 0) {       // 1 2
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getnumeral();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (ennum) && eunum == 0 && esnum == 0) {      // 1 3
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getupper();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (esnum) && eunum == 0 && ennum == 0) {       // 1 4
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getupper();
                        break;
                    case 1:
                        tmpchar = getnumeral();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (eunum) && (ennum) && esnum == 0) {           // 1 2 3
            for (i = 0; i < fillnumber; i++) {
                getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (eunum) && (esnum) && ennum == 0) {          // 1 2 4
            for (i = 0; i < fillnumber; i++) {
                getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (ennum) && (esnum) && eunum == 0) {        // 1 3 4
            for (i = 0; i < fillnumber; i++) {
                getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && elnum == 0 && ennum == 0 && esnum == 0) {            // 2
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 3) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getnumeral();
                        break;
                    case 2:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && (ennum) && elnum == 0 && esnum == 0) {               // 2 3
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && (esnum) && elnum == 0 && esnum == 0) {          // 2 4
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && (ennum) && (esnum) && elnum == 0) {        // 2 3 4
            for (i = 0; i < fillnumber; i++) {
                getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((ennum) && elnum == 0 && eunum == 0 && esnum == 0) {            // 3
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 3) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getupper();
                        break;
                    case 2:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((ennum) && (esnum) && elnum == 0 && eunum == 0) {               // 3 4
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getupper();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((esnum) && elnum == 0 && eunum == 0 && ennum == 0) {            // 4
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 3) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getupper();
                        break;
                    case 2:
                        tmpchar = getnumeral();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                           // END no exclusions

                                                                                        // START -xl
    if (xl == true && xu == false && xn == false && xs == false) {
        if (eunum) {
            for (i = 0; i < eunum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (ennum) {
            for (i = 0; i < ennum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (esnum) {
            for (i = 0; i < esnum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (unum) {
            for (i = 0; i < unum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (nnum) {
            for (i = 0; i < nnum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (snum) {
            for (i = 0; i < snum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (eunum == 0 && ennum == 0 && esnum == 0) {              // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 3) {
                    case 0:
                        tmpchar = getupper();
                        break;
                    case 1:
                        tmpchar = getnumeral();
                        break;
                    case 2:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && ennum == 0 && esnum == 0) {              // 1
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getnumeral();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && (ennum) && esnum == 0) {              // 1 2
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && (esnum) && ennum == 0) {              // 1 3
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((ennum) && eunum == 0 && esnum == 0) {                // 2
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getupper();
                    case 1:
                        tmpchar = getspecial();
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && (esnum) && esnum == 0) {              // 2 3
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((esnum) && eunum == 0 && ennum == 0) {
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {                        // 3
                    case 0:
                        tmpchar = getupper();
                    case 1:
                        tmpchar = getnumeral();
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                                     // END -xl

    if (xl == true && xu == true && xn == false && xs == false) {                   // START -xl -xu
        if (ennum) {
            for (i = 0; i < ennum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (esnum) {
            for (i = 0; i < esnum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (nnum) {
            for (i = 0; i < nnum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (snum) {
            for (i = 0; i < snum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }

        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (ennum == 0 && esnum == 0) {                            // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getnumeral();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((ennum) && esnum == 0) {                            // 1
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((ennum) && (esnum)) {                               // 1 2
            printf("pswd: exact numbers and exclusions make this impossible\n");
            return (EXIT_FAILURE);
        }
        if (ennum == 0 && (esnum)) {                               // 2
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                                 // END -xl -xu

                                                                                    // START -xl -xn
    if (xl == true && xu == false && xn == true && xs == false) {
        if (eunum) {
            for (i = 0; i < eunum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (esnum) {
            for (i = 0; i < esnum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (unum) {
            for (i = 0; i < unum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (snum) {
            for (i = 0; i < snum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (eunum == 0 && esnum == 0) {                         // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getupper();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && esnum == 0) {                            // 1
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && (esnum)) {                               // 1 2
            printf("pswd: exact numbers and exclusions make this impossible\n");
            return (EXIT_FAILURE);
        }
        if (eunum == 0 && (esnum)) {                            // 2
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                                 // END -xl -xn

                                                                                    // START -xl -xs
    if (xl == true && xu == false && xn == false && xs == true) {
        if (eunum) {
            for (i = 0; i < eunum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (ennum) {
            for (i = 0; i < ennum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (unum) {
            for (i = 0; i < unum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (nnum) {
            for (i = 0; i < nnum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (eunum == 0 && ennum == 0) {                            // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getupper();
                        break;
                    case 1:
                        tmpchar = getnumeral();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && ennum == 0) {                                // 1
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && (ennum)) {                                   // 1 2
            printf("pswd: exact numbers and exclusions make this impossible\n");
            return (EXIT_FAILURE);
        }
        if (eunum == 0 && (ennum)) {                                // 2
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                                 // END -xl -xs

                                                                                // START -xl -xu -xn
    if (xl == true && xu == true && xn == true && xs == false) {
        if (esnum) {
            for (i = 0; i < esnum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (snum) {
            for (i = 0; i < snum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (esnum) {
            printf("pswd: exact number and exclusions make this impossible\n");
            return (EXIT_FAILURE);
        }
        if (esnum == 0) {
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                             // END -xl -xu -xn

                                                                                // START -xl -xu -xs
    if (xl == true && xu == true && xn == false && xs == true) {
        if (ennum) {
            for (i = 0; i < ennum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (nnum) {
            for (i = 0; i < nnum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (ennum) {
            printf("pswd: exact number and exclusions make this impossible\n");
            return (EXIT_FAILURE);
        }
        if (ennum == 0) {
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                             // END -xl -xu -xs

                                                                                // START -xl -xn -xs
    if (xl == true && xu == false && xn == true && xs == true) {
        if (eunum) {
            for (i = 0; i < eunum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (unum) {
            for (i = 0; i < unum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (eunum) {
            printf("pswd: exact number and exclusions make this impossible\n");
            return (EXIT_FAILURE);
        }
        if (eunum == 0) {
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                             // END -xl -xn -xs

                                                                                        // START -xu
    if (xl == false && xu == true && xn == false && xs == false) {
        if (elnum) {
            for (i = 0; i < elnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (ennum) {
            for (i = 0; i < ennum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (esnum) {
            for (i = 0; i < esnum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (lnum) {
            for (i = 0; i < lnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (nnum) {
            for (i = 0; i < nnum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (snum) {
            for (i = 0; i < snum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (elnum == 0 && ennum == 0 && esnum == 0) {                     // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 3) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getnumeral();
                        break;
                    case 2:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && ennum == 0 && esnum == 0) {                   // 1
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getnumeral();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (ennum) && esnum == 0) {                   // 1 2
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (esnum) && ennum == 0) {                   // 1 3
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((ennum) && elnum == 0 && esnum == 0) {                   // 2
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((ennum) && (esnum) && elnum == 0) {                   // 2 3
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((esnum) && elnum == 0 && ennum == 0) {                   // 3
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getnumeral();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                                     // END -xu

                                                                                    // START -xu -xn
    if (xl == false && xu == true && xn == true && xs == false) {
        if (elnum) {
            for (i = 0; i < elnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (esnum) {
            for (i = 0; i < esnum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (lnum) {
            for (i = 0; i < lnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (snum) {
            for (i = 0; i < snum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (elnum == 0 && esnum == 0) {                                  // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && esnum == 0) {                                // 1
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) == 0 && (esnum)) {                                // 1 2
            printf("pswd: exact numbers and exclusions make this impossible\n");
            return (EXIT_FAILURE);
        }
        if ((esnum) && elnum == 0) {                                // 2
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                                 // END -xu -xn

                                                                                    // START -xu -xs
    if (xl == false && xu == true && xn == false && xs == true) {
        if (elnum) {
            for (i = 0; i < elnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (ennum) {
            for (i = 0; i < ennum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (lnum) {
            for (i = 0; i < lnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (nnum) {
            for (i = 0; i < nnum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (elnum == 0 && ennum == 0) {                                  // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getnumeral();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && ennum == 0) {                                // 1
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (elnum == 0 && (ennum)) {                                // 1 2
            printf("pswd: exact numbers and exclusions make this impossible\n");
            return (EXIT_FAILURE);
        }
        if ((ennum) && elnum == 0) {                                // 2
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                                 // END -xu -xs

                                                                                // START -xu -xn -xs
    if (xl == false && xu == true && xn == true && xs == true) {
        if (elnum) {
            for (i = 0; i < elnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (lnum) {
            for (i = 0; i < lnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (elnum) {
            printf("pswd: exact number and exclusions make this impossible\n");
            return (EXIT_FAILURE);
        }
        if (elnum == 0) {
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                             // END -xu -xn -xs

                                                                                        // START -xn
    if (xl == false && xu == false && xn == true && xs == false) {
        if (elnum) {
            for (i = 0; i < elnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (eunum) {
            for (i = 0; i < eunum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (esnum) {
            for (i = 0; i < esnum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (lnum) {
            for (i = 0; i < lnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (unum) {
            for (i = 0; i < unum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (snum) {
            for (i = 0; i < snum; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (elnum == 0 && eunum == 0 && esnum == 0) {                     // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 3) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getupper();
                        break;
                    case 2:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && eunum == 0 && esnum == 0) {                   // 1
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getupper();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (eunum) && esnum == 0) {                   // 1 2
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getspecial();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (esnum) && eunum == 0) {                   // 1 3
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && elnum == 0 && esnum == 0) {                   // 2
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getspecial();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && (esnum) && elnum == 0) {                   // 2 3
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((esnum) && elnum == 0 && eunum == 0) {                   // 3
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getupper();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                                     // END -xn

                                                                                    // START -xn -xs
    if (xl == false && xu == false && xn == true && xs == true) {
        if (elnum) {
            for (i = 0; i < elnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (eunum) {
            for (i = 0; i < eunum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (lnum) {
            for (i = 0; i < lnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (unum) {
            for (i = 0; i < unum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (elnum == 0 && eunum == 0) {                                  // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getupper();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && eunum == 0) {                                // 1
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (elnum == 0 && (eunum)) {                                // 1 2
            printf("pswd: exact numbers and exclusions make this impossible\n");
            return (EXIT_FAILURE);
        }
        if ((eunum) && elnum == 0) {                                // 2
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                                 // END -xn -xs

                                                                                        // START -xs
    if (xl == false && xu == false && xn == false && xs == true) {
        if (elnum) {
            for (i = 0; i < elnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (eunum) {
            for (i = 0; i < eunum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (ennum) {
            for (i = 0; i < ennum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (lnum) {
            for (i = 0; i < lnum; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (unum) {
            for (i = 0; i < unum; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (nnum) {
            for (i = 0; i < nnum; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if (strlen(pswd) < PasswordLength) {
            fillnumber = PasswordLength - strlen(pswd);
        }
        if (elnum == 0 && eunum == 0 && ennum == 0) {                     // NULL
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 3) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getupper();
                        break;
                    case 2:
                        tmpchar = getnumeral();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && eunum == 0 && ennum == 0) {                   // 1    
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getupper();
                        break;
                    case 1:
                        tmpchar = getnumeral();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (eunum) && ennum == 0) {                   // 1 2  
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getnumeral();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((elnum) && (ennum) && eunum == 0) {                   // 1   3
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getupper();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && elnum == 0 && ennum == 0) {                   //   2  
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getnumeral();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((eunum) && (ennum) && elnum == 0) {                   //   2 3
            for (i = 0; i < fillnumber; i++) {
                tmpchar = getlower();
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
        if ((ennum) && elnum == 0 && eunum == 0) {                   //     3
            for (i = 0; i < fillnumber; i++) {
                switch (rand() % 2) {
                    case 0:
                        tmpchar = getlower();
                        break;
                    case 1:
                        tmpchar = getupper();
                        break;
                }
                sprintf(pswd + strlen(pswd), "%c", tmpchar);
            }
        }
    }                                                                                     // END -xs
    scramble(pswd, PasswordLength);
    printf("%s\n", pswd);
    return 0;
}                                                                                        // END main


//        printf("elnum = %d  eunum = %d  ennum = %d  esnum = %d\n", elnum, eunum, ennum, esnum);
//        printf("lnum = %d  unum = %d  nnum = %d  snum = %d\n", lnum, unum, nnum, snum);

// all combinations of exclude switches
// xl          case 01 if (xl == true)
// xl xu       case 02 if (xl == true && xu == true)
// xl    xn    case 03 if (xl == true && xn == true)
// xl       xs case 04 if (xl == true && xs == true)
// xl xu xn    case 05 if (xl == true && xu == true && xn == true)
// xl xu    xs case 06 if (xl == true && xu == true && xs == true)
// xl    xn xs case 07 if (xl == true && xn == true && xs == true)
// xl xu xn xs case 08 if (xl == true && xu == true && xn == true && xs == true) -> ERROR
//    xu       case 09 if (xu == true)
//    xu xn    case 10 if (xu == true && xn == true)
//    xu    xs case 11 if (xu == true && xs == true)
//    xu xn xs case 12 if (xu == true && xn == true && xs == true)
//       xn    case 13 if (xn == true)
//       xn xs case 14 if (xn == true && xs == true)
//          xs case 15 if (xs == true)

// 1 2 3 4
// l u n s
// 1 
// 1 2
// 1   3
// 1     4
// 1 2 3
// 1 2   4
// 1   3 4
//   2
//   2 3
//   2   4
//   2 3 4
//     3
//     3 4
//       4
/*
                                                                                                   1                   1                   1
         1         2         3         4         5         6         7         8         9         0                   2                   4
12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/
