#include <Stdio.h>
#include <stdint.h>
#include <stdlib.h>

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

int read_header(const char* path, s_header_t* header)
{
    FILE* f = fopen(path, "rb");

    if(f == NULL)
    {
        printf("Can not open file\n");
        fclose(f);
        return 0;
    }
    fread(header, sizeof(s_header_t), 1, f);
    printf("Header: id=%d, version=%d, record_count=%d\n",
           header->id_file, header->version, header->number_record);
    fclose(f);
    return 1;
}

int read_record(const char* path, s_header_t header, s_weatherRecord_t* record)
{
    FILE* f = fopen(path, "rb");

    if(f == NULL)
    {
        printf("Can not open file\n");
        fclose(f);
        return 0;
    }
    fseek(f, sizeof(s_header_t), SEEK_SET);
    int n = fread(record, sizeof(s_weatherRecord_t), header.number_record, f);
    printf("Read %d records\n", n);
    fclose(f);
    return 1;
}


int main()
{
    s_header_t header;
    char* path = "D:/Desktop/hoc/Tu/Training_lab/Practice_c/File/Read_bin_write_json/weather_data.bin";

    if (!read_header(path, &header))
        return 0;

    s_weatherRecord_t* records = malloc(header.number_record * sizeof(s_weatherRecord_t));
    if (!records) {
        printf("Malloc failed\n");
        return 0;
    }

    if (read_record(path, header, records)) {
        printf("First record id=%u, battery=%u\n",
               records[0].sensor_id, records[0].baterry);
    }

    free(records);
    return 0;
}