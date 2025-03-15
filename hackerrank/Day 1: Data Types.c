    int a;
	float b;
    char *st_input = (char*)malloc(100*sizeof(char));
    
    scanf("%d", &a);
    scanf("%f", &b);
    fflush(stdin);
    strcpy(st_input, "is the best place to learn and practice coding!");
    printf("%d\n%.1f\n%s%s", i+a, d+b, s, st_input);