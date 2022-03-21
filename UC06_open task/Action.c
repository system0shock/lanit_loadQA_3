

Action()
{
	int ticket_random;
	char * id_mem;
	char* check_assign;
	
	lr_think_time(37);

	lr_start_transaction("UC06_TR03_open_random_task");
	

	id_mem=lr_paramarr_random("id_list");


	ticket_random = atoi(id_mem);
	
	lr_save_int(ticket_random, "ticket_num");

	
	web_reg_save_param_ex(
    "ParamName=assignBool",
    "LB=\'owner\'><option value=\'0\'>",
    "RB=</option>",
    "Ordinal=All",
    SEARCH_FILTERS,
    "Scope=Body",
    LAST);

	
	web_url("23", 
		"URL=http://{host}:{port}/tickets/{ticket_num}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC06_TR03_open_random_task",LR_AUTO);
	
	check_assign=lr_eval_string("{assignBool_1}");
	lr_output_message(check_assign);

	
	//if  <td>Unassigned <strong>
	if (strcmp(check_assign, "Unassign")==0){
		lr_output_message("Unassigned");
		lr_start_transaction("UC06_TR04_assign_task");

	web_url("23_2", 
		"URL=http://{host}:{port}/tickets/{ticket_num}/?take", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/{ticket_num}/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC06_TR04_assign_task",LR_AUTO);
	}else{
		lr_output_message("Assigned");
	}
	

	lr_start_transaction("UC06_TR05_logout");

	web_url("Logout", 
		"URL=http://{host}:{port}/logout/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/{ticket_num}/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC06_TR05_logout",LR_AUTO);

	return 0;
}