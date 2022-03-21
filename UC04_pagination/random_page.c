int randomPage(int i){
	int b = atoi(lr_eval_string ("{ticket_list_length}"));
	int result =0;
	if (i<=b) {
		return (0);
	}
	else {
		return result =(rand()%(i / b)*b);
		} 
	}