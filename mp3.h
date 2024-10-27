#ifndef MP3_H
#define MP3_H

#include<stdio.h>
#include<string.h>

typedef struct
{

    int tag_pos[7];

    char*ip_file_name;

    char title_tag[5];
    int size_tile;
    char song_tile[50];

    char artist_tag[5];
    int size_artist;
    char artist_name[50];
    
    char album_tag[5];
    int size_album;
    char album_name[50];

    char year_tag[5];
    int size_year;
    char year[5];

    char genre_tag[5];
    int size_genre;
    char genre[50];

    char comment_tag[5];
    int size_comment;
    char comment[50];

    FILE*fptr_mp3_file;

    FILE*fptr_dup_file;


}MPEGDATA;
void red();
void yellow();
void blue();
void reset();
void cyan();
void green();
void edit_data(MPEGDATA *data,int n,char*argv[]);
void get_tags(MPEGDATA *data);
void open_files(MPEGDATA *data);
void check_id(MPEGDATA *data);
char* read_tag(MPEGDATA *data,char *tag_buffer);
int read_size(MPEGDATA *data,int*ptr);
void view_tags(MPEGDATA *data);
char* read_data(MPEGDATA *data,int size,char* data_buffer);
void Print_view();
#endif