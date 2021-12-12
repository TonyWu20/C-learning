#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

typedef struct
{
    char *id;
    int weight;
} package;

typedef struct
{
    int min_weight;
    int max_weight;
    package *packages;
    int packages_count;
} post_office;

typedef struct
{
    char *name;
    post_office *offices;
    int offices_count;
} town;

void print_all_packages(town t)
{
    printf("%s\n", t.name);
    for (int i = 0; i < t.offices_count; ++i)
    {
        printf("\t%d\n", i);
        for (int j = 0; j < t.offices[i].packages_count; ++j)
        {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town *source, int source_office_index,
                                  town *target, int target_office_index)
{
    post_office *src = &(source->offices[source_office_index]);
    post_office *dst = &(target->offices[target_office_index]);
    int rejId = -1;
    package *rejPkgs = malloc(0);
    for (int i = 0; i < src->packages_count; ++i)
    {
        package pkg = src->packages[i];
        if (pkg.weight >= dst->min_weight && pkg.weight <= dst->max_weight)
        {
            dst->packages_count++;
            dst->packages =
                realloc(dst->packages, sizeof(package) * dst->packages_count);
            dst->packages[dst->packages_count - 1] = pkg;
        }
        else
        {
            rejId++;
            rejPkgs = realloc(rejPkgs, sizeof(package) * (rejId + 1));
            rejPkgs[rejId] = pkg;
        }
    }
    free(src->packages);
    src->packages = rejPkgs;
    src->packages_count = rejId + 1;
}

/**
 * given all towns, find the one with the most number of packages in all post
 * offices altogether. If there are several of them, find the first one from the
 * collection towns
 */
town town_with_most_packages(town *towns, int towns_count)
{
    int mostTownId;
    int mostPackages = 0;
    for (int i = 0; i < towns_count; ++i)
    {
        town curTown = towns[i];
        int totalPackagesCount = 0;
        for (int j = 0; j < curTown.offices_count; ++j)
        {
            totalPackagesCount += curTown.offices[j].packages_count;
        }
        if (mostPackages < totalPackagesCount)
        {
            mostPackages = totalPackagesCount;
            mostTownId = i;
        }
    }
    return towns[mostTownId];
}

/**
 * given all towns and a string name, find the town with the name name. It's
 * guaranteed that the town exists.
 */
town *find_town(town *towns, int towns_count, char *name)
{
    town *ret = NULL;
    for (int i = 0; i < towns_count; ++i)
    {
        if (towns[i].name == name)
        {
            ret = &towns[i];
            break;
        }
    }
    return ret;
}
