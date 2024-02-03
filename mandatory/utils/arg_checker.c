
static int checkdup(int num , char ** av , int i )
{
    while(av[++i])
    {
        if(ft_atoi(av[i]) == num)
            return 1;
    }
    return 0;
}

void arg_checker(int ac , char ** av)
{
    char **arguments;
    int i;
    long ifdup ;

    i = 0;
    if(ac == 2)
        arguments = ft_split(av[1],' ');
    else
    {
        i = 1;
        arguments = av;
    }
    while(arguments[i])
    {
        ifdup = ft_atoi(arguments[i])
        if(!ft_isnum(arguments[i]))
            ft_error("Error");
        if(checkdup(ifdup,arguments, i))
            ft_error("Error");
        if(ifdup < -2147483648 || ifdup > 2147483647)
            ft_error("Error");
        i++;
    }
    if(argc == 2)
        ft_free(arguments);
}