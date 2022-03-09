CreateTask()
{
		lr_start_transaction("UC03_TR03_open_new_ticket_page");

/*Correlation comment - Do not change!  Original value='b68nunNCdyTLVC7YHba9PuPjEfxl4SabQ9jcpTXD457KcCycW2eq554dM00JgWAC' Name ='csrfmiddlewaretoken_1' Type ='ResponseBased'*/
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
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC03_TR03_open_new_ticket_page",LR_AUTO);

	lr_start_transaction("UC03_TR04_submit_new_ticket");
	
	random_word("ticket_title", 12);
    lr_output_message("%s",buff);
    
    
    random_word("ticket_body", 32);
    lr_output_message("%s",buff);
    

	web_submit_data("submit_2",
		"Action=http://{host}:{port}/tickets/submit/",
		"Method=POST",
		"EncType=multipart/form-data",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/tickets/submit/",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrfmiddlewaretoken", "Value={csrfmiddlewaretoken_1}", ENDITEM,
		"Name=queue", "Value={queue}", ENDITEM,
		"Name=title", "Value={ticket_title}", ENDITEM,
		"Name=body", "Value={ticket_body}", ENDITEM,
		"Name=priority", "Value={ticket_priority}", ENDITEM,
		"Name=due_date", "Value={due_date_day}.{due_date_month}.2022", ENDITEM,
		"Name=attachment", "Value=", "File=yes", ENDITEM,
		"Name=submitter_email", "Value=testuser1@test.test", ENDITEM,
		"Name=assigned_to", "Value=2", ENDITEM,
		LAST);

	lr_end_transaction("UC03_TR04_submit_new_ticket",LR_AUTO);
	return 0;
}
