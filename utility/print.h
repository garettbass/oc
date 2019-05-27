#pragma once
#include "../oc.h"

//------------------------------------------------------------------------------

static inline
void
oc_print(const char* s) {
    int indent = 0;
    bool newline = false;
    for (;*s;++s) {
        char c = *s;
        switch (c) {
            case '}':
                indent -= 1;
                break;
        }
        if (newline) {
            newline = false;
            fputc('\n', stdout);
            for (int i = 0; i < indent; ++i)
                fputs("    ", stdout);
        }
        fputc(c, stdout);
        switch (c) {
            case '}':
                newline = true;
                while (s[1] == ' ') ++s;
                break;
            case '{':
                indent += 1;
                newline = true;
                while (s[1] == ' ') ++s;
                break;
            case ';':
                newline = true;
                while (s[1] == ' ') ++s;
                break;
        }
    }
    fputc('\n', stdout);
    fputc('\n', stdout);
}

#define oc_print(...) _oc_print(__VA_ARGS__)
#define _oc_print(...) oc_print(#__VA_ARGS__)
