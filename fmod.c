#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

char class_name[64], func_name[128];
char line[64 * 1024];

int main(int argc, char *argv[]) {
	char *buf = (char *)malloc(1024 * 1024);
	
	char *end_buf = (char *)malloc(1024 * 1024);
	end_buf[0] = '\n';
	end_buf[1] = 0;
	
	FILE *f = fopen("headers/fmod.hpp", "rb");
	fread(buf, 1, 1024 * 1024, f);
	fclose(f);
	
	// fmod.hpp
	f = fopen("source/fmod.cpp", "wb");
	char *cur = strstr(buf, "'System' API");
	cur = strstr(cur, "class ") + strlen("class ");
	char *end = strstr(cur, "\n");
	memcpy(class_name, cur, end - cur);
	class_name[end - cur] = 0;
	cur = strstr(cur, "FMOD_RESULT F_API ") + strlen("FMOD_RESULT F_API ");
	char *class_end = strstr(cur, "};");
	char *start = buf;
	while (strlen(class_name) > 0) {
		printf("Wrapping class %s\n---------\n", class_name);
		while (cur && cur < class_end) {
			char *method_start = cur;
			end = strstr(cur, "(");
			memcpy(func_name, cur, end - cur);
			func_name[end - cur] = 0;
			char *fnc = &func_name[end - cur - 1];
			while (*fnc == ' ') {
				fnc[0] = 0;
				fnc--;
			}
			printf("Wrapping method %s\n", func_name);
			cur = strstr(cur, ") {") + 1;
			char save = cur[0];
			cur[0] = 0;
			fwrite(start, 1, strlen(start), f);
			cur[0] = save;
			save = ';';
			fwrite(&save, 1, 1, f);
			end = strstr(cur, "}");
			end[1] = 0;
			sprintf(line, "FMOD_RESULT F_API FMOD::%s::%s\n", class_name, method_start + 1);
			end[1] = '\n';
			start = end + 1;
			strcat(end_buf, line);
			cur = strstr(cur, "FMOD_RESULT F_API ");
			if (cur)
				cur += strlen("FMOD_RESULT F_API ");
		}
		char *class_start = strstr(class_end, "class ");
		if (class_start) {
			class_start += strlen("class ");
			end = strstr(class_start, "\n");
			char *end2 = strstr(class_start, " :");
			if (end2 && end2 < end)
				end = end2;
			memcpy(class_name, class_start, end - class_start);
			class_name[end - class_start] = 0;
			class_end = strstr(cur, "};");
		} else {
			class_name[0] = 0;
		}
	}
	fwrite(start, 1, strlen(start), f);
	fwrite(end_buf, 1, strlen(end_buf), f);
	fclose(f);
	free(buf);
	free(end_buf);
}