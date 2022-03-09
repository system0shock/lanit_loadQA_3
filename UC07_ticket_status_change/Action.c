char buff[32] = "";
int ticket_random;
char * id_mem;

char* random_word(int length)
{ 
  int r,i;
  char c;
  srand((unsigned int)time(0));

	for (i = 0; i < length; i++){
    r = rand() % 25 + 65;
    c = (char)r;
    buff[i] = c;
    //printf("%c", c);
   
}

//lr_save_string(buff, param_name);
return buff;
}



Action()
{
	char* comment;
	
	lr_think_time(20);

	lr_start_transaction("UC07_TR03_open_random_task");
	
	id_mem=lr_paramarr_random("id_list");
	ticket_random = atoi(id_mem);
	lr_save_int(ticket_random, "ticket_num");
//	lr_save_string(id_mem, "ticket_num");

/*Correlation comment - Do not change!  Original value='znLuxUy3bzfndz18eOQ5u55P54OjkmEsM8j4BaebsFxLmmXgJx9NjJznYn2F2CPk' Name ='csrfmiddlewaretoken_1' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=csrfmiddlewaretoken_1",
		"TagName=input",
		"Extract=value",
		"Name=csrfmiddlewaretoken",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);
	

	web_url("8", 
		"URL=http://{host}:{port}/tickets/{ticket_num}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC07_TR03_open_random_task",LR_AUTO);

	lr_start_transaction("UC07_TR04_assign_new_status");
	
	comment = random_word(10);
	lr_save_string(comment, "random_ticket_comment");

	web_submit_data("update",
		"Action=http://{host}:{port}/tickets/{ticket_num}/update/",
		"Method=POST",
		"EncType=multipart/form-data",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/tickets/{ticket_num}/",
		"Snapshot=t12.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=comment", "Value={random_ticket_comment}", ENDITEM,
		"Name=new_status", "Value={random_ticket_status}", ENDITEM,
		"Name=public", "Value=1", ENDITEM,
		"Name=time_spent", "Value=", ENDITEM,
		"Name=title", "Value=tyarwhlafrgkggakjkul", ENDITEM,
		"Name=owner", "Value=0", ENDITEM,
		"Name=priority", "Value=4", ENDITEM,
		"Name=due_date", "Value=", ENDITEM,
		"Name=attachment", "Value=", "File=yes", ENDITEM,
		"Name=csrfmiddlewaretoken", "Value={csrfmiddlewaretoken_1}", ENDITEM,
		LAST);

	lr_end_transaction("UC07_TR04_assign_new_status",LR_AUTO);

	lr_start_transaction("UC07_TR05_logout");

	web_url("Logout", 
		"URL=http://{host}:{port}/logout/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/{ticket_num}/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC07_TR05_logout",LR_AUTO);

	return 0;
}