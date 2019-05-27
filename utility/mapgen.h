#pragma once
#include <assert.h>
#include <stdio.h>

static inline
void
oc_fmapgen(FILE* const file, const char* map, const unsigned max)
{
    assert(file);
    fprintf(file, "#pragma once\n\n");

    fprintf(file, "//------------------------------------------------------------------------------\n\n");

    fprintf(file, "#define %1$s_concat(A, B) _%1$s_concat(A, B)\n", map);
    fprintf(file, "#define _%s_concat(A, B) A ## B\n\n", map);

    fprintf(file, "//------------------------------------------------------------------------------\n\n");

    fprintf(file, "#define %s_count(...)\\\n", map);
    fprintf(file, "        _%s_count(__VA_ARGS__,", map);
    for (unsigned i = 0; i < max; ++i)
    {
        if (i % 16 == 0) fprintf(file, "\\\n            ");
        fprintf(file, "%u,", max - i);
    }
    fprintf(file, "end)\n");
    fprintf(file, "#define _%s_count(", map);
    for (unsigned i = 0; i < max; ++i)
    {
        if (i % 16 == 0) fprintf(file, "\\\n            ");
        fprintf(file, "_%u,", max - i);
    }
    fprintf(file, "X,...) X\n\n");

    fprintf(file, "//------------------------------------------------------------------------------\n\n");

    fprintf(file, "#define %s(M, ...)\\\n", map);
    fprintf(file, "        %1$s_concat(_%1$s_, %1$s_count(__VA_ARGS__))(M, __VA_ARGS__)\n", map);
    for (unsigned i = 1; i <= max; ++i)
    {
        fprintf(file, "#define _%s_%u(M", map, i);
        for (unsigned j = 1; j <= i; ++j) fprintf(file, ", _%u", j);
        fprintf(file, ")\\\n");

        fprintf(file, "        ");
        for (unsigned j = 1; j <= i; ++j) fprintf(file, "M(_%u)", j);
        fprintf(file, "\n");
    }
    fprintf(file, "\n");

    fprintf(file, "//------------------------------------------------------------------------------\n\n");

    fprintf(file, "#define %s1(M, A, ...)\\\n", map);
    fprintf(file, "        %1$s_concat(_%1$s1_, %1$s_count(__VA_ARGS__))(M, A, __VA_ARGS__)\n", map);
    for (unsigned i = 1; i <= max; ++i)
    {
        fprintf(file, "#define _%s1_%u(M, A", map, i);
        for (unsigned j = 1; j <= i; ++j) fprintf(file, ", _%u", j);
        fprintf(file, ")\\\n");

        fprintf(file, "        ");
        for (unsigned j = 1; j <= i; ++j) fprintf(file, "M(A,_%u)", j);
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    fprintf(file, "//------------------------------------------------------------------------------\n\n");
}

static inline
void
_oc_mapgen(const char* path, const char* map, const unsigned max)
{
    FILE* const file = fopen(path, "w");
    oc_fmapgen(file, map, max);
    fclose(file);
}
