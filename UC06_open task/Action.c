//int randomTicket(int i){
//		int result;
//		result=rand()%(i +1);
//		return result;
//}


Action()
{
//	int elemCnt;
	int ticket_random;
//	char ticketNumber[12] = "id_list_";
	char * id_mem;
//	int id;
//	char* x;
	char* check_assign;
	
	lr_think_time(37);

	lr_start_transaction("TR03_open_random_task");
	
//	x = lr_eval_string("id_list_count");
//	sscanf(x, "%04d", &elemCnt);
//	elemCnt = atoi(x);
//	elemCnt = 20;
	
//	lr_output_message("Number of items found = %d",elemCnt);
//	id = randomTicket(elemCnt);
//	lr_output_message("id = %d",id);
	id_mem=lr_paramarr_random("id_list");


	ticket_random = atoi(id_mem);
	
	lr_save_int(ticket_random, "ticket_num");
//	lr_output_message("Ticket number %s", "{ticket_num}");
//	sprintf(id_mem, "%d", id);
//	strcat(ticketNumber, id_mem);
//	lr_save_string(ticketNumber, "{true_id}");
//	ticket_random=lr.eval_int("{true_id}");
//	lr_save_int(ticket_random, "{ticket_num}");
	
	web_reg_save_param_ex(
    "ParamName=assignBool",
    "LB=\'owner\'><option value=\'0\'>",
    "RB=</option>",
    "Ordinal=All",
    SEARCH_FILTERS,
    "Scope=Body",
    LAST);
	//lr_output_message({assignBool});
	
	lr_save_string(lr_eval_string("assign_Bool_1"), "check_assign");
	//check_assign=web_convert_param("assignBool"
	
	web_url("23", 
		"URL=http://{host}:{port}/tickets/{ticket_num}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR03_open_random_task",LR_AUTO);

	
	//if  <td>Unassigned <strong>
	if (check_assign=="Unassign"){
		lr_output_message("Unassign");
		lr_start_transaction("TR05_assign_task");

	web_url("23_2", 
		"URL=http://{host}:{port}/tickets/{ticket_num}/?take", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/{ticket_num}/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR05_assign_task",LR_AUTO);
	}else{
		lr_output_message("assign");
	}
	

	lr_start_transaction("TR06_logout");

	web_url("Logout", 
		"URL=http://{host}:{port}/logout/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/{ticket_num}/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR06_logout",LR_AUTO);

	return 0;
}