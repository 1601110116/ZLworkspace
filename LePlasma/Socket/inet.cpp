
#include"inet.h"

int connectSocket(const char* serveraddr,int port){
	struct sockaddr_in client_addr;
	bzero(&client_addr,sizeof(client_addr));
	
	client_addr.sin_family = AF_INET; 
	client_addr.sin_addr.s_addr = htons(INADDR_ANY);
	client_addr.sin_port = htons(0);
	
	int client_socket = socket(AF_INET,SOCK_STREAM,0);
	
	if( client_socket < 0){
		printf("Create Socket Failed!\n");
		return -1;
	}

	if( bind(client_socket,(struct sockaddr*)&client_addr,sizeof(client_addr))){
		printf("Client Bind Port Failed!\n");  
		return -1;
	}

	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family = AF_INET;

	if(inet_aton(serveraddr,&server_addr.sin_addr) == 0){
		printf("Server IP Address Error!\n");
		return -1;
	}
	

	server_addr.sin_port = htons(port);
	socklen_t server_addr_length = sizeof(server_addr);

	if(connect(client_socket,(struct sockaddr*)&server_addr, server_addr_length) < 0) {
		printf("Can Not Connect To %s!\n",serveraddr);
		return -1;
	}else{
		printf("Connect %s:%d Success\n",serveraddr,port);
	}

	return client_socket;
}


int openListening(int port){
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htons(INADDR_ANY); 

	if(port==-1) server_addr.sin_port = htons(0);
	else server_addr.sin_port = htons(port);

	
	int server_socket = socket(AF_INET,SOCK_STREAM,0);
	if( server_socket < 0){  
		printf("Create Socket Failed!");  
		return -1;
	}  
	int option = 1;
	setsockopt(server_socket,SOL_SOCKET,SO_REUSEADDR,(const char*)&option,sizeof(int));
	if( bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr))){  
		printf("Server Bind Port : %d Failed!", port);  
		return -1; 
	}

	if(listen(server_socket, 1) ){
		printf("Server Listen Failed!");  
		return -1;
	} 
	return server_socket;
}

int acceptSocket(int listen_socket){
	struct sockaddr_in client_addr;
	socklen_t length = sizeof(client_addr);

	static int num=0;
	num++;
	int new_server_socket = accept(listen_socket,(struct sockaddr*)&client_addr,&length);
	if ( new_server_socket < 0){
		printf("Server Accept Failed!\n");
		return -1;
	}

	return(new_server_socket);
}

bool Recv(int socket, void* buffer, int len){

	int bufferLen;
	int recvLen=0;
	do{
		bufferLen=recv(socket,buffer+recvLen,len-recvLen,0);
		if(bufferLen<0)return false;
		recvLen+=bufferLen;
	}while(recvLen<len);

	return true;
}

