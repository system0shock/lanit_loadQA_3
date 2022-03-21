char buff[32] = "";

random_word(char* param_name, int length)
{ 
  int r,i;
  char c;
  srand((unsigned int)time(0));

for (i = 0; i < length; i++)
{
    r = rand() % 25 + 65;
    c = (char)r;
    buff[i] = c;
    printf("%c", c);
   
}

lr_save_string(buff, param_name);
return 0;

}