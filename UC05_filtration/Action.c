Action()
{
	randNum = rand()%19 + 1;
	randSave= rand()%10+1;
	lr_think_time(50);


switch (randNum){
	case 1:
		lr_save_string("?sortx=title&date_from=&date_to=&q=", "filter");
	case 2:
		lr_save_string("?sortx=created&date_from=&date_to=&q=", "filter");
	case 3:
		lr_save_string("?sortx=queue&date_from=&date_to=&q=", "filter");
	case 4:
		lr_save_string("?sortx=status&date_from=&date_to=&q=", "filter");
	case 5:
		lr_save_string("?sortx=priority&date_from=&date_to=&q=", "filter");
	case 6:
		lr_save_string("?sortx=assigned_to&date_from=&date_to=&q=", "filter");
	case 7:
		lr_save_string("?sortx=assigned_to&date_from=&date_to=&q=", "filter");
	case 8:
		lr_save_string("?assigned_to=-1&date_from=&date_to=&q=", "filter");
	case 9:
		lr_save_string("?queue=1&date_from=&date_to=&q=", "filter");
	case 10:
		lr_save_string("?queue=2&date_from=&date_to=&q=", "filter");
	case 11:
		lr_save_string("?status=1&date_from=&date_to=&q=", "filter");
	case 12:
		lr_save_string("?status=2&date_from=&date_to=&q=", "filter");
	case 13:
		lr_save_string("?status=3&date_from=&date_to=&q=", "filter");
	case 14:
		lr_save_string("?status=4&date_from=&date_to=&q=", "filter");
	case 15:
		lr_save_string("?status=5&date_from=&date_to=&q=", "filter");
	case 16:
		lr_save_string("?date_from=&date_to=&q=&kbitem=-1", "filter");
	case 17:
		lr_save_string("?date_from=&date_to=&q=&kbitem=1", "filter");
	case 18:
		lr_save_string("?date_from=&date_to=&q=&kbitem=2", "filter");
	case 19:
		lr_save_string("?date_from=&date_to=&q=&kbitem=3", "filter");		
}


	lr_start_transaction("UC05_TR03_add_filter");

/*Correlation comment - Do not change!  Original value='CnDcONRBiwfGBCppJqRLHnh6QWg0Wf4bcyxgvjdNHEOZOtSDzxkg3PyuLxPCxs8D' Name ='csrfmiddlewaretoken_1' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=csrfmiddlewaretoken_1",
		"TagName=input",
		"Extract=value",
		"Name=csrfmiddlewaretoken",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/tickets/*",
		LAST);
		
	web_reg_save_param_ex(
    	"ParamName=query_encoded",
    	"LB=encoded\' value=\'",
    	"RB=\'",
    	"Ordinal=all",
    	"Notfound=warning",
    	LAST);
    

	web_url("tickets", 
		"URL=http://{host}:{port}/tickets/{filter}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("{query_encoded_1}", 
		"URL=http://{host}:{port}/datatables_ticket_list/{query_encoded_1}?draw=1&columns%5B0%5D%5Bdata%5D=id&columns%5B0%5D%5Bname%5D=&columns%5B0%5D%5Bsearchable%5D=true&columns%5B0%5D%5Borderable%5D="
		"false&columns%5B0%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B0%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B1%5D%5Bdata%5D=ticket&columns%5B1%5D%5Bname%5D=&columns%5B1%5D%5Bsearchable%5D=true&columns%5B1%5D%5Borderable%5D=true&columns%5B1%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B1%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B2%5D%5Bdata%5D=priority&columns%5B2%5D%5Bname%5D=&columns%5B2%5D%5Bsearchable%5D=true&columns%5B2%5D%5Borderable%5D=true&columns%5B2%5D%5Bsearch%5D%5Bvalue%5D=&"
		"columns%5B2%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B3%5D%5Bdata%5D=queue&columns%5B3%5D%5Bname%5D=&columns%5B3%5D%5Bsearchable%5D=true&columns%5B3%5D%5Borderable%5D=true&columns%5B3%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B3%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B4%5D%5Bdata%5D=status&columns%5B4%5D%5Bname%5D=&columns%5B4%5D%5Bsearchable%5D=true&columns%5B4%5D%5Borderable%5D=true&columns%5B4%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B4%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B5%5D%5Bdata%5D=created&"
		"columns%5B5%5D%5Bname%5D=&columns%5B5%5D%5Bsearchable%5D=true&columns%5B5%5D%5Borderable%5D=true&columns%5B5%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B5%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B6%5D%5Bdata%5D=due_date&columns%5B6%5D%5Bname%5D=&columns%5B6%5D%5Bsearchable%5D=true&columns%5B6%5D%5Borderable%5D=true&columns%5B6%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B6%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B7%5D%5Bdata%5D=assigned_to&columns%5B7%5D%5Bname%5D=&columns%5B7%5D%5Bsearchable%5D=true&"
		"columns%5B7%5D%5Borderable%5D=true&columns%5B7%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B7%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B8%5D%5Bdata%5D=submitter&columns%5B8%5D%5Bname%5D=&columns%5B8%5D%5Bsearchable%5D=true&columns%5B8%5D%5Borderable%5D=true&columns%5B8%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B8%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B9%5D%5Bdata%5D=time_spent&columns%5B9%5D%5Bname%5D=&columns%5B9%5D%5Bsearchable%5D=true&columns%5B9%5D%5Borderable%5D=true&"
		"columns%5B9%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B9%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B10%5D%5Bdata%5D=kbitem&columns%5B10%5D%5Bname%5D=&columns%5B10%5D%5Bsearchable%5D=true&columns%5B10%5D%5Borderable%5D=true&columns%5B10%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B10%5D%5Bsearch%5D%5Bregex%5D=false&order%5B0%5D%5Bcolumn%5D=0&order%5B0%5D%5Bdir%5D=asc&start=0&length=25&search%5Bvalue%5D=&search%5Bregex%5D=false&_=1646170347340", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host}:{port}/tickets/{filter}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC05_TR03_add_filter",LR_AUTO);

lr_think_time(50);


if (randSave==1) {
	random_word("query_title", 10);
    lr_output_message("%s",buff);
	lr_start_transaction("UC05_TR03_add_filter");

/*Correlation comment - Do not change!  Original value='CnDcONRBiwfGBCppJqRLHnh6QWg0Wf4bcyxgvjdNHEOZOtSDzxkg3PyuLxPCxs8D' Name ='csrfmiddlewaretoken_1' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=csrfmiddlewaretoken_1",
		"TagName=input",
		"Extract=value",
		"Name=csrfmiddlewaretoken",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/tickets/*",
		LAST);
	
	web_reg_save_param_ex(
    	"ParamName=query_encoded",
    	"LB=encoded\' value=\'",
    	"RB=\'",
    	"Ordinal=all",
    	"Notfound=warning",
    	LAST);

	web_url("tickets", 
		"URL=http://{host}:{port}/tickets/{filter}", 
		//"URL=http://{host}:{port}/tickets/{filter_type}{filter_value}&date_from=&date_to=&q=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("{query_encoded_1}", 
		"URL=http://{host}:{port}/datatables_ticket_list/{query_encoded_1}?draw=1&columns%5B0%5D%5Bdata%5D=id&columns%5B0%5D%5Bname%5D=&columns%5B0%5D%5Bsearchable%5D=true&columns%5B0%5D%5Borderable%5D="
		"false&columns%5B0%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B0%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B1%5D%5Bdata%5D=ticket&columns%5B1%5D%5Bname%5D=&columns%5B1%5D%5Bsearchable%5D=true&columns%5B1%5D%5Borderable%5D=true&columns%5B1%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B1%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B2%5D%5Bdata%5D=priority&columns%5B2%5D%5Bname%5D=&columns%5B2%5D%5Bsearchable%5D=true&columns%5B2%5D%5Borderable%5D=true&columns%5B2%5D%5Bsearch%5D%5Bvalue%5D=&"
		"columns%5B2%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B3%5D%5Bdata%5D=queue&columns%5B3%5D%5Bname%5D=&columns%5B3%5D%5Bsearchable%5D=true&columns%5B3%5D%5Borderable%5D=true&columns%5B3%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B3%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B4%5D%5Bdata%5D=status&columns%5B4%5D%5Bname%5D=&columns%5B4%5D%5Bsearchable%5D=true&columns%5B4%5D%5Borderable%5D=true&columns%5B4%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B4%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B5%5D%5Bdata%5D=created&"
		"columns%5B5%5D%5Bname%5D=&columns%5B5%5D%5Bsearchable%5D=true&columns%5B5%5D%5Borderable%5D=true&columns%5B5%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B5%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B6%5D%5Bdata%5D=due_date&columns%5B6%5D%5Bname%5D=&columns%5B6%5D%5Bsearchable%5D=true&columns%5B6%5D%5Borderable%5D=true&columns%5B6%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B6%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B7%5D%5Bdata%5D=assigned_to&columns%5B7%5D%5Bname%5D=&columns%5B7%5D%5Bsearchable%5D=true&"
		"columns%5B7%5D%5Borderable%5D=true&columns%5B7%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B7%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B8%5D%5Bdata%5D=submitter&columns%5B8%5D%5Bname%5D=&columns%5B8%5D%5Bsearchable%5D=true&columns%5B8%5D%5Borderable%5D=true&columns%5B8%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B8%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B9%5D%5Bdata%5D=time_spent&columns%5B9%5D%5Bname%5D=&columns%5B9%5D%5Bsearchable%5D=true&columns%5B9%5D%5Borderable%5D=true&"
		"columns%5B9%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B9%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B10%5D%5Bdata%5D=kbitem&columns%5B10%5D%5Bname%5D=&columns%5B10%5D%5Bsearchable%5D=true&columns%5B10%5D%5Borderable%5D=true&columns%5B10%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B10%5D%5Bsearch%5D%5Bregex%5D=false&order%5B0%5D%5Bcolumn%5D=0&order%5B0%5D%5Bdir%5D=asc&start=0&length=25&search%5Bvalue%5D=&search%5Bregex%5D=false&_=1646170347340", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host}:{port}/tickets/{filter}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC05_TR03_add_filter",LR_AUTO);

	lr_start_transaction("TR04_save_query");

	web_submit_data("save_query",
		"Action=http://{host}:{port}/save_query/",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/tickets/{filter}",
		"Snapshot=t10.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrfmiddlewaretoken", "Value={csrfmiddlewaretoken_1}", ENDITEM,
		"Name=query_encoded", "Value={query_encoded_1}", ENDITEM,
		"Name=title", "Value={query_title}", ENDITEM,
		"Name=shared", "Value=on", ENDITEM,
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("{query_encoded_1}", 
		"URL=http://{host}:{port}/datatables_ticket_list/{query_encoded_1}?draw=1&columns%5B0%5D%5Bdata%5D=id&columns%5B0%5D%5Bname%5D=&columns%5B0%5D%5Bsearchable%5D=true&columns%5B0%5D%5Borderable%5D=false&columns%5B0%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B0%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B1%5D%5Bdata%5D=ticket&columns%5B1%5D%5Bname%5D=&columns%5B1%5D%5Bsearchable%5D=true&"
		"columns%5B1%5D%5Borderable%5D=true&columns%5B1%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B1%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B2%5D%5Bdata%5D=priority&columns%5B2%5D%5Bname%5D=&columns%5B2%5D%5Bsearchable%5D=true&columns%5B2%5D%5Borderable%5D=true&columns%5B2%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B2%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B3%5D%5Bdata%5D=queue&columns%5B3%5D%5Bname%5D=&columns%5B3%5D%5Bsearchable%5D=true&columns%5B3%5D%5Borderable%5D=true&columns%5B3%5D%5Bsearch%5D%5Bvalue%5D=&"
		"columns%5B3%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B4%5D%5Bdata%5D=status&columns%5B4%5D%5Bname%5D=&columns%5B4%5D%5Bsearchable%5D=true&columns%5B4%5D%5Borderable%5D=true&columns%5B4%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B4%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B5%5D%5Bdata%5D=created&columns%5B5%5D%5Bname%5D=&columns%5B5%5D%5Bsearchable%5D=true&columns%5B5%5D%5Borderable%5D=true&columns%5B5%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B5%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B6%5D%5Bdata%5D=due_date"
		"&columns%5B6%5D%5Bname%5D=&columns%5B6%5D%5Bsearchable%5D=true&columns%5B6%5D%5Borderable%5D=true&columns%5B6%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B6%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B7%5D%5Bdata%5D=assigned_to&columns%5B7%5D%5Bname%5D=&columns%5B7%5D%5Bsearchable%5D=true&columns%5B7%5D%5Borderable%5D=true&columns%5B7%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B7%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B8%5D%5Bdata%5D=submitter&columns%5B8%5D%5Bname%5D=&columns%5B8%5D%5Bsearchable%5D=true&"
		"columns%5B8%5D%5Borderable%5D=true&columns%5B8%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B8%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B9%5D%5Bdata%5D=time_spent&columns%5B9%5D%5Bname%5D=&columns%5B9%5D%5Bsearchable%5D=true&columns%5B9%5D%5Borderable%5D=true&columns%5B9%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B9%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B10%5D%5Bdata%5D=kbitem&columns%5B10%5D%5Bname%5D=&columns%5B10%5D%5Bsearchable%5D=true&columns%5B10%5D%5Borderable%5D=true&"
		"columns%5B10%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B10%5D%5Bsearch%5D%5Bregex%5D=false&order%5B0%5D%5Bcolumn%5D=0&order%5B0%5D%5Bdir%5D=asc&start=0&length=25&search%5Bvalue%5D=&search%5Bregex%5D=false&_=1646170374689", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR04_save_query",LR_AUTO);
	
	lr_start_transaction("UC05_TR05_logout");

	web_url("logout", 
		"URL=http://{host}:{port}/logout/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC05_TR05_logout",LR_AUTO);
	return 0;
} else {

	

	lr_start_transaction("UC05_TR05_logout");

	web_url("logout", 
		"URL=http://{host}:{port}/logout/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC05_TR05_logout",LR_AUTO);

			return 0;
}
	
}