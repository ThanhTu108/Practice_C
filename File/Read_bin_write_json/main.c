#include <Stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define NUMBER 2000

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
    float hum;
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

void write_json(const char* path, s_header_t header, s_weatherRecord_t* record)
{
    FILE* f = fopen(path, "w");
    if (f == NULL) {
        printf("Can not open json file\n");
        return;
    }

    fprintf(f, "{\n");
    fprintf(f, "\t\"header\": \n\t{\n");
    fprintf(f, "\t\t\"id_file\": %u,\n", header.id_file);
    fprintf(f, "\t\t\"file version\": %u,\n", header.version);
    fprintf(f, "\t\t\"number record\": %u\n", header.number_record);
    fprintf(f, "\t},\n");

    fprintf(f, "\t\"record\": \n\t[\n");
    for(uint32_t i = 0; i < NUMBER; i++)
    {
        fprintf(f, "\t\t{\n");
        fprintf(f, "\t\t\t\"Sensor_id\": %u,\n", (record+i)->sensor_id);
        fprintf(f, "\t\t\t\"Battery\": %u,\n", (record+i)->baterry);
        fprintf(f, "\t\t\t\"Time\": %u,\n", (record+i)->timestamp);
        fprintf(f, "\t\t\t\"Latitude\": %f,\n", (record+i)->lati);
        fprintf(f, "\t\t\t\"Longitude\": %f,\n", (record+i)->longi);
        fprintf(f, "\t\t\t\"Temperature\": %f,\n", (record+i)->temp);
        fprintf(f, "\t\t\t\"humidity\": %f,\n", (record+i)->hum);
        fprintf(f, "\t\t\t\"Pressure\": %f,\n", (record+i)->press);
        fprintf(f, "\t\t\t\"Co2\": %u,\n", (record+i)->co2);
        fprintf(f, "\t\t\t\"Wind speed\": %f,\n", (record+i)->wind_speed);
        fprintf(f, "\t\t\t\"Wind direction\": %u,\n", (record+i)->wind_direction);
        fprintf(f, "\t\t\t\"Rain fall\": %f,\n", (record+i)->rain_fall);
        fprintf(f, "\t\t\t\"Uv\": %f,\n", (record+i)->uv);
        fprintf(f, "\t\t\t\"Light\": %f\n", (record+i)->light);
        if (i == NUMBER - 1)
            fprintf(f,"\t\t}\n");
        else
            fprintf(f, "\t\t},\n");
    }
    fprintf(f,"\t]\n");
    fprintf(f, "}\n");
}


int main()
{
    s_header_t header;
    char* path_bin = "D:/Desktop/hoc/Tu/Training_lab/Practice_c/File/Read_bin_write_json/weather_data.bin";
    char* path_json = "../weather_record.json";

    if (!read_header(path_bin, &header))
        return 0;

    s_weatherRecord_t* records = malloc(header.number_record * sizeof(s_weatherRecord_t));
    if (!records) {
        printf("Malloc failed\n");
        return 0;
    }

    if (read_record(path_bin, header, records)) {
        printf("First record id=%u, battery=%u\n",
               records[0].sensor_id, records[0].baterry);
    }
    write_json(path_json, header, records);
    free(records);
    return 0;
}