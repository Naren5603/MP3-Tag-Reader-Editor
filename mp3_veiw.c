
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mp3.h"
#include <stdint.h>
void print_equalto()
{
    for(int i=0;i<80;i++)
    {
        printf("-");
    }
}

void get_tags(MPEGDATA *data)
{
    open_files(data);

    fseek(data->fptr_mp3_file,10,SEEK_SET);
    // printf("--------------------------SONG DETAILS------------------------\n");
    for(int i=0;i<=6;i++)
    {
        data->tag_pos[i]=ftell(data->fptr_mp3_file);
        char*tag_buffer=malloc(5);
        tag_buffer=read_tag(data,tag_buffer);
        int size;
        int *ptr;

        size=read_size(data,ptr);
        char data_buffer[size];
        strcpy(data_buffer,read_data(data,size-1,data_buffer));

        if(i==0)
        {
            strcpy(data->title_tag,tag_buffer);

            data->size_tile=size;

            strcpy(data->song_tile,data_buffer);
        }
        if(i==1)
        {
            strcpy(data->artist_tag,tag_buffer);

            data->size_artist=size;

            strcpy(data->artist_name,data_buffer);
        }
        if(i==2)
        {
            strcpy(data->album_tag,tag_buffer);

            data->size_album=size;

            strcpy(data->album_name,data_buffer);
        }
        if(i==3)
        {
            strcpy(data->year_tag,tag_buffer);

            data->size_year=size;

            strcpy(data->year,data_buffer);
        }
        if(i==4)
        {
            strcpy(data->genre_tag,tag_buffer);

            data->size_genre=size;

            strcpy(data->genre,data_buffer);
        }
        if(i==5)
        {
            strcpy(data->comment_tag,tag_buffer);

            data->size_comment=size;

            strcpy(data->comment,data_buffer);
        }
    }
}

void view_tags(MPEGDATA *data)
{
    print_equalto();
    printf("\n");
    cyan();
    printf("\t\t\tMP3 Tag Reader and Editor for ID3V2");
    reset();
    printf("\n");
    print_equalto();
    printf("\n");
    blue();
    printf("%-20s:\t%s\n","TITLE",data->song_tile);
    printf("%-20s:\t%s\n","ARTIST",data->artist_name);
    printf("%-20s:\t%s\n","ALBUM",data->album_name);
    printf("%-20s:\t%s\n","YEAR",data->year);
    printf("%-20s:\t%s\n","GENRA",data->genre);
    printf("%-20s:\t%s\n","LANGUAGE",data->comment);
    reset();
    print_equalto();
    printf("\n");

}

void open_files(MPEGDATA *data)
{
    data->fptr_mp3_file=fopen(data->ip_file_name,"r");
    if(data->fptr_mp3_file==NULL)
    {
        printf("Unable to open the file\nPlease check if the file is present in the directry\n");
        exit(0);
    }
}

void check_id(MPEGDATA *data)
{
    fseek(data->fptr_mp3_file,0,SEEK_SET);
    char id[3];
        fread(id,3,1,data->fptr_mp3_file);

    if(strcmp(id,"ID3")!=0)
    {
        printf("Unsuporrted file");
        exit(0);
    }
    printf("ID Matched\n");
}

char* read_tag(MPEGDATA *data,char*tag_buffer)
{
    char image_buffer[5];
    fread(image_buffer,4,1,data->fptr_mp3_file);
    image_buffer[5]='\0';
    strcpy(tag_buffer,image_buffer);
    return tag_buffer;
}

int read_size(MPEGDATA *data,int *size)
{
    int siz=0;
    fread(&siz,4,1,data->fptr_mp3_file);
    siz=__builtin_bswap32(siz);
    return siz;
}

char* read_data(MPEGDATA *data,int size,char* data_buffer)
{
    fseek(data->fptr_mp3_file,3,SEEK_CUR);
    char image_buffer[size];
    fread(image_buffer,size,1,data->fptr_mp3_file);
    image_buffer[size]='\0';
    strcpy(data_buffer,image_buffer);
    return data_buffer;
}

void Print_view()
{
    yellow();
    printf("--------------------------HELP MENU------------------------\n");
    printf("1.  -v  -> to view mp3 file contents\n");
    printf("2.  -e  -> to edit mp3 file contents\n");
    printf("2.1.    -t  ->  to edit song title\n");
    printf("2.2.    -a  ->  to edit artist name\n");
    printf("2.3.    -A  ->  to edit album name\n");
    printf("2.4.    -y  ->  to edit year\n");
    printf("2.5.    -m  ->  to edit genra\n");
    printf("2.6.    -c  ->  to edit language\n");
    printf("-----------------------------------------------------------\n");
    printf("\n");
    reset();
}
