#include <stdio.h>
#include <string.h>
#include <stdint.h>

unsigned char head[] = {
    0x6F,0x63,0x33,0x7C,0x6B,0x34,0x73,0x6F,0x34,0x58,0x74,0x6C,0x7E,0x58,0x61,
    0x66,0x6B,0x6B,0x2E
};

void print_flag(void) {
    unsigned char key = "[REDACTED]"; 
    unsigned char buf[128];
    size_t i = 0;
    while (head[i] != 0x00 && i < sizeof(buf)-1) {
        buf[i] = head[i];
        i++;
    }
    puts("=== MESSAGE FROM 007 ===");
    puts((char *)head);
    puts("=======================");
}

void vuln(void) {
    char buf[64];
    puts("Incoming message from field agent. Type your passphrase:");
    gets(buf);
    puts("Thanks. Story transferred.");
}

int main(int argc, char **argv) {
    vuln();
    puts("Disconnecting...");
    return 0;
}
