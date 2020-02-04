#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include "cJSON.c"
#include "cJSON.h"
#include <time.h>
#define MAX 80
#define PORT 12345
#define SA struct sockaddr

struct user {
    char token [12] ;
     boolean i ;
    char username [100] ;
     boolean x ;
    char  cname [20] ;
};
struct user u [1000] ;

int i=0 ;

char *randstring(int length) {
    static int mySeed = 25011984;
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    size_t stringLen = strlen(string);
    char *randomString = NULL;

    srand(time(NULL) * length + ++mySeed);

    if (length < 1) {
        length = 1;
    }

    randomString = malloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;

        for (int n = 0;n < length;n++) {
            key = rand() % stringLen;
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;
    }
    else {
        printf("No memory");
        exit(1);
    }
}

 char* concat(int count, ...)
{
    va_list ap;
    int i;

    // Find required length to store merged string
    int len = 1; // room for NULL
    va_start(ap, count);
    for(i=0 ; i<count ; i++)
        len += strlen(va_arg(ap, char*));
    va_end(ap);

    // Allocate memory to concat strings
    char *merged = calloc(sizeof(char),len);
    int null_pos = 0;

    // Actually concatenate strings
    va_start(ap, count);
    for(i=0 ; i<count ; i++)
    {
        char *s = va_arg(ap, char*);
        strcpy(merged+null_pos, s);
        null_pos += strlen(s);
    }
    va_end(ap);

    return merged;
}

 void regis (char buffer [1000], int client_socket)
{   char respond [1000] ;
    char username [100] ;
    char  password  [100];
    char string_0 [256] ;
     sscanf (buffer,"%*s %s %s",username,password);
  for (int i=0;;i++){
    if (username[i]==','){
      username[i]='\0';
      break;
    }
  }
    //printf("%s %s\n" ,username , password) ;
    cJSON *user = cJSON_CreateObject () ;
    FILE * fptr = fopen( "usernamepass.txt" , "a+") ;
    if (fptr == NULL)
    {
        cJSON *type = cJSON_CreateString ("Error ") ;
        cJSON *content = cJSON_CreateString ("") ;
        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user )) ;
        send(client_socket, respond, sizeof(respond), 0);

    }
    while ((fgets (string_0, 256,fptr)) != NULL )
    {   char   x [100];
        sscanf (string_0 , "%s %*s" , x);
        printf ("%s \n" , x) ;
        if (strcmp (x,username) == 0)
        {
            cJSON *type = cJSON_CreateString ("Error") ;
        cJSON *content = cJSON_CreateString ("user already exists") ;
        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user) ) ;

        send(client_socket, respond, sizeof(respond), 0);
         return ;

        }

    }
strcat(username , " ") ;
strcat(username , password ) ;
strcat(username , "\n") ;
   fprintf(fptr , username) ;
   cJSON *type = cJSON_CreateString ("Successful") ;
        cJSON *content = cJSON_CreateString ("") ;
        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user) ) ;
send(client_socket, respond, sizeof(respond), 0);

}
void login (char buffer [1000] , int client_socket )
{
    char respond [1000] ;
    char username [100] ;
    char password [100] ;
    char string_0 [256] ;
     sscanf (buffer,"%*s %s %s",username,password);

  for (int i=0;;i++){
    if (username[i]==','){
      username[i]='\0';
      break;
    }
  }
   cJSON *user = cJSON_CreateObject () ;

for (int i; i < 1000 ; i ++)
{
    if (strcmp (u[i].username , username) == 0 )
    {
        if (strcmp(u[i].token, "000000000000") != 0 )
        {
            cJSON *type = cJSON_CreateString ("Error") ;
        cJSON *content = cJSON_CreateString ("user already logged in") ;
        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user )) ;
        send(client_socket, respond, sizeof(respond), 0);
        }
    }
}




    FILE * fptr = fopen( "usernamepass.txt" , "r") ;
    if (fptr == NULL)
    {
        cJSON *type = cJSON_CreateString ("Error") ;
        cJSON *content = cJSON_CreateString ("") ;
        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user )) ;
        send(client_socket, respond, sizeof(respond), 0);
    }

    while ((fgets (string_0, 256,fptr)) != NULL )
    {
        string_0 [strlen(string_0) - 1]  = '\0' ;

        char  x [100] ;
        char   y [100] ;
        sscanf (string_0 , "%s %s" , x , y);

      //  printf("%s %s\n" ,x , y ) ;

        if (strcmp (x,username) == 0)
        {
            if ( strcmp(y,password) == 0 )
          {
        strcpy (u[i].token , randstring(12));
        strcpy (u[i].username , username ) ;
        cJSON * type = cJSON_CreateString ("Authtoken") ;
        cJSON * content = cJSON_CreateString (u[i].token) ;
        printf("%s \n" ,u[i].token) ;
        strcpy(u[i].cname , "000000000000") ;
        i++;

        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user) ) ;

        send(client_socket, respond, sizeof(respond), 0);
        return ;
          }
          else
          {
              cJSON * type = cJSON_CreateString ("Error") ;
        cJSON * content = cJSON_CreateString ("password is not correct") ;
        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user) ) ;
        send(client_socket, respond, sizeof(respond), 0);
        return ;
          }

        }

    }
    cJSON * type = cJSON_CreateString ("Error") ;
        cJSON * content = cJSON_CreateString ("user don't exist") ;
        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user) ) ;
               send(client_socket, respond, sizeof(respond), 0);


//printf("%s \n" , u[0].token) ;

}
void logout (char buffer [1000] ,int client_socket)
{
    char respond [1000] ;
    char token [12] ;
    sscanf(buffer , "%*s %s", token );

    for (int j =0 ; j < 1000 ; j++)
    {
       if (strcmp( token , u[j].token) == 0)
       {
           memset(u[j].token , 0 , 12 ) ;
           break ;
       }

    }
    cJSON *user = cJSON_CreateObject ()  ;
    cJSON *type = cJSON_CreateString ("Successful") ;
    cJSON *content = cJSON_CreateString ("") ;
    cJSON_AddItemToObject (user , "type" , type ) ;
    cJSON_AddItemToObject (user , "content" , content ) ;
    strcpy(respond , cJSON_Print (user) ) ;

   send(client_socket, respond, sizeof(respond), 0);

}
void createc (char buffer [1000] , int client_socket )
{
    char respond [1000] ;
    char cname [20] ;
    char token [12] ;

    char string_0 [256] ;
    buffer [strlen(buffer) - 1 ] = '\0' ;


  sscanf(buffer ,"%*s %*s %s"  , cname ) ;

      for (int i=0;;i++){
    if (cname[i]==','){
      cname[i]='\0';
      break;
    }
  }

        cJSON * user = cJSON_CreateObject () ;
        printf("%s \n" , cname) ;



    FILE * fptr = fopen( "channelinfo.txt" , "a+") ;
     while ((fgets (string_0, 256,fptr)) != NULL )
    {   char   x [100];

        sscanf (string_0 , "%s %*s" , x);
        if (strcmp (x,cname) == 0)
        {
            cJSON *type = cJSON_CreateString ("Error") ;
        cJSON *content = cJSON_CreateString ("channel already exists") ;
        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user) ) ;

        send(client_socket, respond, sizeof(respond), 0);
         return ;

        }

    }
 char x [20] ;
    strcpy(x, cname ) ;
  strcat (cname , "\n") ;
    fprintf(fptr , cname ) ;
    cJSON *type = cJSON_CreateString ("Successful") ;
    cJSON *content = cJSON_CreateString ("") ;
    cJSON_AddItemToObject (user , "type" , type ) ;
    cJSON_AddItemToObject (user , "content" , content ) ;
    strcpy(respond , cJSON_Print (user) ) ;
    send(client_socket, respond, sizeof(respond), 0);


    sscanf(buffer , "%*s %*s %*s %s", token ) ;
    printf ("%s %s \n" ,x ,token );


    for (int j = 0 ; j < 1000 ; j++ )
    {
        if (strcmp ( u[j].token , token) == 0 )
        {
            for ( int h = 0 ; ; h++)
            {
                u[j].cname[h] = x[h] ;
                if (x[h] == '\0')
                    break ;
            }
           // printf("%s \n" , u[j].cname ) ;
            break ;

        }

    }

//printf("%s \n" , u[0].token) ;

strcat(x, ".txt") ;
 FILE * nw = fopen( x , "w") ;
    }

void cmember (char buffer [1000] , int client_socket )
{
 char respond [1000] ;
 char token [12] ;
 char cname [20] ;

 sscanf(buffer ,"%*s %*s %s"  , token ) ;

 printf("%s\n" , token ) ;
      cJSON * user = cJSON_CreateObject () ;
    cJSON *type = cJSON_CreateString ("list") ;
    cJSON *members = cJSON_CreateArray() ;
     //printf("%s \n" , u[0].token) ;
    for ( int j = 0 ; j < 1000 ; j ++)
    {
        if (strcmp (token , u[j].token) == 0)
        { printf("fucktoken\n") ;


            strcpy (cname , u[j].cname ) ;

            break ;
        }
    }
    printf("%s \n" ,cname);
    for ( int j = 0 ; j < 1000 ; j++ )
    {
        if (strcmp (cname , u[j].cname) == 0 )
        {
            cJSON * str = cJSON_CreateString (u[j].username) ;
       //     printf("%s \n " , u[j].username) ;
            cJSON_AddItemToArray(members , str) ;
        }
    }
    cJSON_AddItemToObject(user , "type" , type) ;
    cJSON_AddItemToObject(user , "content" , members) ;
      strcpy(respond , cJSON_Print (user) ) ;
    send(client_socket, respond, sizeof(respond), 0);

//printf("%s \n" , u[0].token) ;

}



void joinc (char buffer [1000] , int client_socket )
{
    char cname [100] ;
    char token [12] ;
    char x [12];
    char string_0 [256];
    char respond [1000] ;
    sscanf(buffer , "%*s %*s %*s %s",token) ;
    strcpy(x , token ) ;
    sscanf(buffer ,"%*s %*s %s" , cname ) ;
      for (int i=0;;i++){
    if (cname[i]==','){
      cname[i]='\0';
      break;
    }
  }
  printf("%s \n",u[0].token) ;
  printf("%s %s\n" ,cname , x ) ;
  for (int j = 0;j < 1000;j++){
    if (strcmp(u[j].token , x) == 0 )
    {
        cJSON * user = cJSON_CreateObject () ;
        if ( strcmp(u[j].cname , "000000000000") == 0 )
           {
               FILE * fptr = fopen( "channelinfo.txt" , "a+") ;
     while ((fgets (string_0, 256,fptr)) != NULL )
    {   char   y [20];

        sscanf (string_0 , "%s %*s" , y);
        if (strcmp (y,cname) == 0)
        {
             strcpy(u[j].cname , cname ) ;

    cJSON *type = cJSON_CreateString ("Successful") ;
    cJSON *content = cJSON_CreateString ("") ;
    cJSON_AddItemToObject (user , "type" , type ) ;
    cJSON_AddItemToObject (user , "content" , content ) ;
    strcpy(respond , cJSON_Print (user) ) ;
    send(client_socket, respond, sizeof(respond), 0);


         return ;

        }

    }
    cJSON *type = cJSON_CreateString ("Error") ;
        cJSON *content = cJSON_CreateString ("channel already exists") ;
        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user) ) ;
        send(client_socket, respond, sizeof(respond), 0);

           }
        else
        {
            cJSON * type = cJSON_CreateString ("Error") ;
        cJSON * content = cJSON_CreateString ("user is already in a channel") ;
        cJSON_AddItemToObject (user , "type" , type ) ;
        cJSON_AddItemToObject (user , "content" , content ) ;
        strcpy(respond , cJSON_Print (user) ) ;
               send(client_socket, respond, sizeof(respond), 0);


        }
    }
  }

}
void csend (char buffer [1000] , int client_socket )
{
    char message [100] ;
    char respond [100] ;
    char token [12] ;
  char cname [20] ;
  char line [200] ;
  sscanf(buffer , "%*s %*s %s" , token ) ;

  printf("%s\n"  , token ) ;
  int j ;
  for ( j = 0 ; j < 1000 ; j++)
  {
    if ( strcmp(u[j].token , token) == 0)
       {

           break ;
       }
  }
  sscanf(buffer , "%*s %[^\n]" , message ) ;
   for (int i=0;;i++){
    if (message[i]==','){
      message[i]='\0';
      break;
    }
  }
  strcpy(cname , u[j].cname) ;
  strcat(cname , ".txt") ;
  FILE *fc = fopen(cname , "a+") ;
  strcpy( line , concat(4 , u[j].username , " " , message , "\n"));
  fprintf(fc , line ) ;
    cJSON *user =cJSON_CreateObject () ;
    cJSON *type = cJSON_CreateString ("Successful") ;
    cJSON *content = cJSON_CreateString ("") ;
    cJSON_AddItemToObject (user , "type" , type ) ;
    cJSON_AddItemToObject (user , "content" , content ) ;
    strcpy(respond , cJSON_Print (user) ) ;
    send(client_socket, respond, sizeof(respond), 0);

}

void leave (char buffer [1000] , int client_socket )
{
    char respond [1000] ;
    char token [12] ;
    sscanf(buffer  , "%*s %s" , token ) ;
    for ( int j = 0 ; j < 1000 ; j++ )
    {
        if (strcmp(token, u[j].token) == 0 )
        {
            memset( u[j].cname , 0 , sizeof ( u[j].cname ) );
            break ;
        }
    }
    cJSON * user = cJSON_CreateObject () ;
    cJSON *type = cJSON_CreateString ("Successful") ;
    cJSON *content = cJSON_CreateString ("") ;
    cJSON_AddItemToObject (user , "type" , type ) ;
    cJSON_AddItemToObject (user , "content" , content ) ;
    strcpy(respond , cJSON_Print (user) ) ;
    send(client_socket, respond, sizeof(respond), 0);

}
void refresh (char buffer [1000] , int client_socket )
{
    char respond [1000] ;
    char token [12] ;
    sscanf( buffer , "%*s %s", token );
    char cname [50] ;
    char string_0 [256] ;
    int j;
  //  printf("%s \n", token ) ;
    for ( j = 0; j < 1000 ; j++)
    {
        if (strcmp (u[j].token , token) == 0)
        break ;
    }
    strcpy(cname , u[j].cname );
    strcat(cname , ".txt") ;
    FILE * fc = fopen (cname , "a+") ;
    cJSON * user = cJSON_CreateObject() ;
    cJSON * arr = cJSON_CreateArray() ;
     while ((fgets (string_0, 256,fc)) != NULL )
    {
        string_0 [strlen(string_0) - 1]  = '\0' ;

        char  x [100] ;
        char   y [100] ;
        sscanf (string_0 , "%s %s" , x , y);
    //    printf("%s %s \n",x , y) ;
        cJSON * item =cJSON_CreateObject() ;
        cJSON * sender = cJSON_CreateString(x) ;
        cJSON * message = cJSON_CreateString(y) ;
        cJSON_AddItemToObject (item, "sender" , sender ) ;
        cJSON_AddItemToObject (item , "content" , message ) ;
        cJSON_AddItemToArray(arr , item ) ;
    }
    cJSON *type = cJSON_CreateString ("list") ;
    cJSON_AddItemToObject(user , "type" , type) ;
    cJSON_AddItemToObject(user , "content" , arr) ;
      strcpy(respond , cJSON_Print (user) ) ;
      //printf("%s \n" , respond ) ;
    send(client_socket, respond, sizeof(respond), 0);

}

void recive (int client_socket)
{
    char  buffer [1000] ;

    recv(client_socket , buffer , sizeof (buffer) , 0) ;
    char x [10] ;
    sscanf(buffer , "%s %*s", x) ;
    //printf ("%s\n" ,x) ;
    if (strcmp(x , "channel") == 0)
        {
            cmember ( buffer ,client_socket ) ;
        }
    if (buffer [0] == 'r' && buffer [2] == 'g')
       regis (buffer,client_socket) ;
    if (buffer [0] == 'l' && buffer [3] == 'i')
         login (buffer , client_socket ) ;
    if (buffer [0] == 'l' && buffer [3] == 'o')
        logout (buffer ,client_socket ) ;
    if (buffer [0] == 'r' && buffer [2] == 'f')
        refresh (buffer , client_socket ) ;
    if (buffer [0] == 's' && buffer [1] == 'e')
        csend (buffer , client_socket) ;

    if (buffer [0] == 'j')
        joinc (buffer ,  client_socket ) ;
    if (buffer [0] == 'c'&& buffer [1] == 'r')
       createc ( buffer , client_socket ) ;
    if (buffer [0] == 'l' && buffer [1] == 'e')
        leave( buffer , client_socket ) ;



}

// Driver function
int main()
{
    while (1) {
    int server_socket, client_socket;
    struct sockaddr_in server, client;

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

	// Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        // Tell the user that we could not find a usable Winsock DLL.
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

    // Create and verify socket
    server_socket = socket(AF_INET, SOCK_STREAM, 6);
	if (server_socket == INVALID_SOCKET)
        wprintf(L"socket function failed with error = %d\n", WSAGetLastError() );
    else
        printf("Socket successfully created..\n");

    // Assign IP and port
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    // Bind newly created socket to given IP and verify
    if ((bind(server_socket, (SA *)&server, sizeof(server))) != 0)
    {
        printf("Socket binding failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully bound..\n");

    // Now server is ready to listen and verify
    if ((listen(server_socket, 5)) != 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");

    // Accept the data packet from client and verify
    int len = sizeof(client);
    client_socket = accept(server_socket, (SA *)&client, &len);
    if (client_socket < 0)
    {
        printf("Server accceptance failed...\n");
        exit(0);
    }
    else
        printf("Server acccepted the client..\n");

    // Function for chatting between client and server
    recive (client_socket);

    // Close the socket
    closesocket(server_socket);
}
}
