UC10_new_ticket_creation()
{

	lr_think_time(128);

	lr_start_transaction("UC10_TR06_open_new_ticket_form");

/*Correlation comment - Do not change!  Original value='otqHLTJMPzPFGgShI0xDdVT4qirfdkpKVsPf3HPLxbE6la03Yul5PxeF1OP7uySL' Name ='csrfmiddlewaretoken_1' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=csrfmiddlewaretoken_1",
		"TagName=input",
		"Extract=value",
		"Name=csrfmiddlewaretoken",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_url("submit", 
		"URL=http://{host}:{port}/tickets/submit/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("UC10_TR06_open_new_ticket_form",LR_AUTO);

	
	random_word("ticket_title", 12);
    lr_output_message("%s",buff);
    
    
    random_word("ticket_body", 32);
    lr_output_message("%s",buff);

	lr_start_transaction("UC10_TR07_submit_new_ticket");

	web_submit_data("submit_2",
		"Action=http://{host}:{port}/tickets/submit/",
		"Method=POST",
		"EncType=multipart/form-data",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/tickets/submit/",
		"Snapshot=t41.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrfmiddlewaretoken", "Value={csrfmiddlewaretoken_1}", ENDITEM,
		"Name=queue", "Value={queue}", ENDITEM,
		"Name=title", "Value={ticket_title}", ENDITEM,
		"Name=body", "Value={ticket_body}", ENDITEM,
		"Name=priority", "Value={ticket_priority}", ENDITEM,
		"Name=due_date", "Value={due_date_day}.{due_date_month}.2022", ENDITEM,
		"Name=attachment", "Value=", "File=yes", ENDITEM,
		"Name=submitter_email", "Value={login}@example.org", ENDITEM,
		"Name=assigned_to", "Value={user_ID}", ENDITEM,
		LAST);

	lr_end_transaction("UC10_TR07_submit_new_ticket",LR_AUTO);

	return 0;
}
