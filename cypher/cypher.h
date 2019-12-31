void onCrypt(bool encrypt);

char replace(char x, char adder);
char extract(char y, char adder);

char *cypher(char *text, char *key, int len, int keylen);
char *decypher(char *text, char *key, int len, int keylen);