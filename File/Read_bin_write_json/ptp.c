/**
 * @file    main.c
 * @brief   Read bin convert to json file
 *
 * @date    2025-09-24
 */

/*********************
 *      INCLUDES
 *********************/
#include <Stdio.h>
#include <stdint.h>
#include <stdlib.h>
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
#pragma pack(1)
typedef struct
{
    uint32_t id_file;
    uint16_t version;
    uint32_t number_record;
} s_header_t;
#pragma pack()

#pragma pack(1)
typedef struct
{
    uint32_t sensor_id;
    uint8_t baterry;
    uint32_t timestamp;
    double lati;
    double longi;
    float temp;
    float hump;
    float press;
    uint16_t co2;
    float wind_speed;
    uint16_t wind_direction;
    float rain_fall;
    float uv;
    float light;  
} s_weatherRecord_t;
#pragma pack()
//64byte: 57+1+7padding

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
// s_weatherRecord_t* read_file_bin(const char* path_file, s_header_t* header);
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
int main()
{
    s_header_t header;
    printf("%d\n", sizeof(s_weatherRecord_t));
    s_weatherRecord_t* record;
    char* path = "D:/Desktop/hoc/Tu/Training_lab/Practice_c/File/Read_bin_write_json/weather_data.bin";
    if(read_file_bin(path, &header, &record)) 
    {
        printf("First record id=%u\n", record[0].sensor_id);
        printf("temperature=%f\n", record[0].temp);
        free(record);
    }
    return 0;
}
/**********************
 *   STATIC FUNCTIONS
//  **********************/
int read_file_bin(const char* path_file, s_header_t* header, s_weatherRecord_t** record)
{
    FILE* f = fopen(path_file, "rb");
    if(f == NULL)
    {
        printf("Can't not open file\n");
        fclose(f);
        return 0;
    }
    fread(header, sizeof(s_header_t), 1, f);
    printf("Header: id=%d, version=%d, record_count=%d\n",
           header->id_file, header->version, header->number_record);
    
    *record = (s_weatherRecord_t* )malloc(header->number_record * sizeof(s_weatherRecord_t));

    if(*record == NULL)
    {
        printf("Can't allocate memory");
        fclose(f);
        return 0;
    }
    int n = fread(*record, sizeof(s_weatherRecord_t), header->number_record, f);
    printf("Read %d records\n", n);
    fclose(f);
    return 1;
}
