/* -------------------------------------------------------------------------------
	Script Title       : 
	Script Description : 
                        
                        
	Recorder Version   : 911
   ------------------------------------------------------------------------------- */

vuser_init()
{
	
	char alpha;
	web_add_cookie("csrftoken=Z3rEe2cIEcUV6kCnfcLYGGDk5CUO6z2GE6Ct9ymJvJ8Unk3Bu3PfWhSednnciDs7; DOMAIN={host}");

	web_url("{host}:{port}", 
		"URL=http://{host}:{port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_concurrent_start(NULL);

	web_url("helpdesk-customize.css", 
		"URL=http://{host}:{port}/static/helpdesk/helpdesk-customize.css", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=http://{host}:{port}/", 
		"Snapshot=t2.inf", 
		LAST);

	web_add_header("Origin", 
		"http://{host}:{port}");

	web_url("fa-regular-400.eot", 
		"URL=http://{host}:{port}/static/helpdesk/vendor/fontawesome-free/webfonts/fa-regular-400.eot?", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/vnd.ms-fontobject", 
		"Referer=http://{host}:{port}/", 
		"Snapshot=t3.inf", 
		LAST);

	web_add_header("Origin", 
		"http://{host}:{port}");

	web_url("fa-solid-900.eot", 
		"URL=http://{host}:{port}/static/helpdesk/vendor/fontawesome-free/webfonts/fa-solid-900.eot?", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/vnd.ms-fontobject", 
		"Referer=http://{host}:{port}/", 
		"Snapshot=t4.inf", 
		LAST);

	web_add_header("Origin", 
		"http://{host}:{port}");

	web_url("fa-regular-400.woff", 
		"URL=http://{host}:{port}/static/helpdesk/vendor/fontawesome-free/webfonts/fa-regular-400.woff", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=font/woff", 
		"Referer=http://{host}:{port}/", 
		"Snapshot=t5.inf", 
		LAST);

	web_add_header("Origin", 
		"http://{host}:{port}");

	web_url("fa-solid-900.woff", 
		"URL=http://{host}:{port}/static/helpdesk/vendor/fontawesome-free/webfonts/fa-solid-900.woff", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=font/woff", 
		"Referer=http://{host}:{port}/", 
		"Snapshot=t6.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_set_sockets_option("SSL_VERSION", "2&3");


	lr_think_time(25);

	lr_start_transaction("UC04_TR01_open_login_page");

/*Correlation comment - Do not change!  Original value='Wjwfc1jwvZAapb0OttWdGoPrMbrMu0JOBmH47xtxmwO9Gbr2Ik0uWZ4lUWUaG49f' Name ='csrfmiddlewaretoken' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=csrfmiddlewaretoken",
		"TagName=input",
		"Extract=value",
		"Name=csrfmiddlewaretoken",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/login/*",
		LAST);

	web_url("login", 
		"URL=http://{host}:{port}/login/?next=/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC04_TR01_open_login_page",LR_AUTO);

	lr_start_transaction("UC04_TR02_user_login");

/*Correlation comment - Do not change!  Original value='DQYmSSPrUpGQQus23gCjB49Mp7Ri9JsCEJ8ewN4JkHJ4guIC1LbZYKQyBRvc2wau' Name ='csrftoken' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=csrftoken",
		"RegExp=csrftoken=(.*?);",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/login/*",
		LAST);
	
	web_reg_save_param_ex(
    	"ParamName=query_encoded",
    	"LB=encoded\' value=\'",
    	"RB=\'",
    	"Ordinal=all",
    	"Notfound=warning",
    	LAST);

	web_submit_data("login_2",
		"Action=http://{host}:{port}/login/",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/login/?next=/",
		"Snapshot=t13.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
		"Name=next", "Value=/", ENDITEM,
		"Name=csrfmiddlewaretoken", "Value={csrfmiddlewaretoken}", ENDITEM,
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");
		
	web_set_max_html_param_len("15000");
	web_reg_save_param_ex(
    "ParamName=entries",
    "LB=, \"recordsTotal\": ",
    "RB=,",
    SEARCH_FILTERS,
    "Scope=Body",
    LAST);
	
	
	web_url("{query_encoded_1}", 
		"URL=http://{host}:{port}/datatables_ticket_list/{query_encoded_1}?draw=1&columns%5B0%5D%5Bdata%5D=id&columns%5B0%5D%5Bname%5D=&columns%5B0%5D%5Bsearchable%5D=true&columns%5B0%5D%5Borderable%5D=false&columns%5B0%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B0%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B1%5D%5Bdata%5D=ticket&columns%5B1%5D%5Bname%5D=&columns%5B1%5D%5Bsearchable%5D=true&"
		"columns%5B1%5D%5Borderable%5D=true&columns%5B1%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B1%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B2%5D%5Bdata%5D=priority&columns%5B2%5D%5Bname%5D=&columns%5B2%5D%5Bsearchable%5D=true&columns%5B2%5D%5Borderable%5D=true&columns%5B2%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B2%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B3%5D%5Bdata%5D=queue&columns%5B3%5D%5Bname%5D=&columns%5B3%5D%5Bsearchable%5D=true&columns%5B3%5D%5Borderable%5D=true&columns%5B3%5D%5Bsearch%5D%5Bvalue%5D=&"
		"columns%5B3%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B4%5D%5Bdata%5D=status&columns%5B4%5D%5Bname%5D=&columns%5B4%5D%5Bsearchable%5D=true&columns%5B4%5D%5Borderable%5D=true&columns%5B4%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B4%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B5%5D%5Bdata%5D=created&columns%5B5%5D%5Bname%5D=&columns%5B5%5D%5Bsearchable%5D=true&columns%5B5%5D%5Borderable%5D=true&columns%5B5%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B5%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B6%5D%5Bdata%5D=due_date"
		"&columns%5B6%5D%5Bname%5D=&columns%5B6%5D%5Bsearchable%5D=true&columns%5B6%5D%5Borderable%5D=true&columns%5B6%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B6%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B7%5D%5Bdata%5D=assigned_to&columns%5B7%5D%5Bname%5D=&columns%5B7%5D%5Bsearchable%5D=true&columns%5B7%5D%5Borderable%5D=true&columns%5B7%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B7%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B8%5D%5Bdata%5D=submitter&columns%5B8%5D%5Bname%5D=&columns%5B8%5D%5Bsearchable%5D=true&"
		"columns%5B8%5D%5Borderable%5D=true&columns%5B8%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B8%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B9%5D%5Bdata%5D=time_spent&columns%5B9%5D%5Bname%5D=&columns%5B9%5D%5Bsearchable%5D=true&columns%5B9%5D%5Borderable%5D=true&columns%5B9%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B9%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B10%5D%5Bdata%5D=kbitem&columns%5B10%5D%5Bname%5D=&columns%5B10%5D%5Bsearchable%5D=true&columns%5B10%5D%5Borderable%5D=true&"
		"columns%5B10%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B10%5D%5Bsearch%5D%5Bregex%5D=false&order%5B0%5D%5Bcolumn%5D=0&order%5B0%5D%5Bdir%5D=asc&start=0&length=25&search%5Bvalue%5D=&search%5Bregex%5D=false&_=1646131385967", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);
	
	totalQueries = atoi(lr_eval_string ("{entries}"));
	
    
	lr_end_transaction("UC04_TR02_user_login",LR_AUTO);

//	i = atoi(entries);
//lr_log_message({entries});

	return 0;
}