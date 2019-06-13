int checkUsername(char *username){
	int i, usrnm_size, aux;

	usrnm_size = strlen(username);

	for(i = 0; i < usrnm_size; i++){
		aux = username[i];

		if((aux >= 0) && (aux <= 47)){ // after this interval we have the ASCII numbers
			return -1;
		}else if((aux >= 58) && (aux <= 64)){ // after this interval we have ASCII capital letters
			return -1;
		}else if((aux >= 91) && (aux <= 96)){ // after this interval we have ASCII letters
			return -1;
		}else if((aux >= 123) && (aux <= 127)){ // the rest of ASCII
			return -1;
		}
	}

	return 0;
}
