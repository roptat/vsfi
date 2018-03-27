char sfi$id[0x200000] = "";

int main(unsigned int i) {
    char *t = sfi$id + 550;
    t[5] = i;
    t[i%16] = 5;
    return t[5];
}
