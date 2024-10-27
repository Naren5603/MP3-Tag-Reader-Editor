#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mp3.h"
void print();
void blue()
{
    printf("\033[0;36m");
}
void red()
{
    printf("\033[0;31m");
}
void yellow()
{
    printf(" \033[0;33m");
}
void cyan()
{
    printf("\033[0;34m");
}
void green()
{
    printf("\033[0;32m");
}
void reset()
{
    printf("\033[0m");
}
int main(int argc, char *argv[])
{
    MPEGDATA data;
    if (argc == 1)
    {
        print();
        exit(0);
    }

    else if (strcmp(argv[1], "-v") == 0)
    {
        if (argv[2] == NULL)
        {
            printf("Pass the mpeg file also\n");
            exit(0);
        }
        else if (strstr(argv[2], ".mpeg") != NULL)
        {
            data.ip_file_name = argv[2];
            get_tags(&data);
            view_tags(&data);
        }
    }
    else if (strcmp(argv[1], "-e") == 0)
    {
        if (argv[2] == NULL)
        {
            print();
            exit(0);
        }

        else if (strcmp(argv[2], "-t") == 0)
        {
            if (argv[3] != NULL)
            {
                if (argv[4] != NULL)
                {
                    data.ip_file_name = argv[3];
                    data.fptr_mp3_file = fopen(data.ip_file_name, "r");
                    data.fptr_dup_file = fopen("dup.mpeg", "w");

                    get_tags(&data);

                    edit_data(&data,0,argv);
                }

                else
                {
                    cyan();
                    printf("Pass the new data");
                    reset();
                    exit(0);
                }
                green();
                printf("Title changed successfully\n");
                reset();
            }
            else
            {
                cyan();
                printf("Pass the mpeg file also\n");
                reset();
                exit(0);
            }
        }

        else if (strcmp(argv[2], "-a") == 0)
        {
            if (argv[3] != NULL)
            {
                if (argv[4] != NULL)
                {
                    data.ip_file_name = argv[3];
                    data.fptr_mp3_file = fopen(data.ip_file_name, "r");
                    data.fptr_dup_file = fopen("dup.mpeg", "w");

                    get_tags(&data);

                    edit_data(&data,1,argv);
                }
                else
                {
                    cyan();
                    printf("Pass the new data");
                    reset();
                    exit(0);
                }
                green();
                printf("Artist name changed successfully\n");
                reset();
            }
            else
            {
                cyan();
                printf("Pass the mpeg file also\n");
                reset();
                exit(0);
            }          
        }

        else if (strcmp(argv[2], "-A") == 0)
        {
            if (argv[3] != NULL)
            {
                if (argv[4] != NULL)
                {
                    data.ip_file_name = argv[3];
                    data.fptr_mp3_file = fopen(data.ip_file_name, "r");
                    data.fptr_dup_file = fopen("dup.mpeg", "w");

                    get_tags(&data);

                    edit_data(&data,2,argv);
                }
                else
                {
                    cyan();
                    printf("Pass the new data");
                    reset();
                    exit(0);
                }
                green();
                printf("Album name changed successfully\n");
                reset();

            }
            else
            {
                cyan();
                printf("Pass the mpeg file also\n");
                reset();
                exit(0);
            }
        }

        else if (strcmp(argv[2], "-y") == 0)
        {
            if (argv[3] != NULL)
            {
                if (argv[4] != NULL)
                {
                    data.ip_file_name = argv[3];
                    data.fptr_mp3_file = fopen(data.ip_file_name, "r");
                    data.fptr_dup_file = fopen("dup.mpeg", "w");

                    get_tags(&data);

                    edit_data(&data,3,argv);

                }
                else
                {
                    cyan();
                    printf("Pass the new data");
                    reset();
                    exit(0);
                }
            }
            else
            {
                cyan();
                printf("Pass the mpeg file also\n");
                reset();
                exit(0);
            }
            green();
            printf("Year changed successfully\n");
            reset();
        }
    
            else if (strcmp(argv[2], "-m") == 0)
        {
            if (argv[3] != NULL)
            {
                if (argv[4] != NULL)
                {
                    data.ip_file_name = argv[3];
                    data.fptr_mp3_file = fopen(data.ip_file_name, "r");
                    data.fptr_dup_file = fopen("dup.mpeg", "w");

                    get_tags(&data);

                    edit_data(&data,4,argv);
                }
                else
                {
                    cyan();
                    printf("Pass the new data");
                    reset();
                    exit(0);
                }
                green();
                printf("Genra changed successfully\n");
                reset();

            }
            else
            {
                cyan();
                printf("Pass the mpeg file also\n");
                reset();
                exit(0);
            }
        }
            else if (strcmp(argv[2], "-c") == 0)
        {
            if (argv[3] != NULL)
            {
                if (argv[4] != NULL)
                {
                    data.ip_file_name = argv[3];
                    data.fptr_mp3_file = fopen(data.ip_file_name, "r");
                    data.fptr_dup_file = fopen("dup.mpeg", "w");

                    get_tags(&data);

                    edit_data(&data,5,argv);
                }
                else
                {
                    cyan();
                    printf("Pass the new data");
                    reset();
                    exit(0);
                }
            }
            else
            {
                cyan();
                printf("Pass the mpeg file also\n");
                reset();
                exit(0);
            }
            green();
            printf("Language changed successfully\n");
            reset();

        }
    }
    else if (strcmp(argv[1], "--help") == 0)
    {
        Print_view();
    }
    else
    {
        red();
        print();
        reset();
    }
    return 0;
}

void print()
{
    red();
    printf("ERROR : ./a.out : INVALID ARGUMENTS\n");
    printf("USAGE : \n");
    printf("To view please pass like : ./a.out -v mp3filename\n");
    printf("To edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename \n");
    printf("To get help pass like : ./a.out -help \n");
}

void edit_data(MPEGDATA *data,int n,char *argv[])
{
                    rewind(data->fptr_mp3_file);
                    fseek(data->fptr_dup_file, 0, SEEK_SET);

                    char image[500];
                    fread(image, data->tag_pos[n], 1, data->fptr_mp3_file);
                    fwrite(image, data->tag_pos[n], 1, data->fptr_dup_file);

                    fread(image, 4, 1, data->fptr_mp3_file);
                    fwrite(image, 4, 1, data->fptr_dup_file);
                    
                    int val=__builtin_bswap32(strlen(argv[4])+1);
                    fwrite(&val,4,1,data->fptr_dup_file);
                    fseek(data->fptr_mp3_file,4,SEEK_CUR);

                    fread(image, 3, 1, data->fptr_mp3_file);
                    fwrite(image, 3, 1, data->fptr_dup_file);

                    fwrite(argv[4], strlen(argv[4]), 1, data->fptr_dup_file);

                    fseek(data->fptr_mp3_file, data->tag_pos[n+1], SEEK_SET);
                    while (fread(image, 1, 1, data->fptr_mp3_file) > 0)
                    {
                        fwrite(image, 1, 1, data->fptr_dup_file);
                    }
}
