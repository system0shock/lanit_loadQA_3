/* -------------------------------------------------------------------------------
	Script Title       : 
	Script Description : 
                        
                        
	Recorder Version   : 911
   ------------------------------------------------------------------------------- */

vuser_init()
{

	web_add_cookie("csrftoken=ImVCXIrqLcjD1qD5Ykm2FVZE9YrFto2sa8OHsLJKUVQWnFcjcuxdnUcmXlA2RqPs; DOMAIN={host}");

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

	lr_think_time(19);

	lr_start_transaction("UC07_TR01_open_login_page");

/*Correlation comment - Do not change!  Original value='DrUVr8HF0Zrz6LFXVYOEsefLzsaqxSLE5dN0WbZZ9IYSs0eb98ZPadstnPjNVUyE' Name ='csrfmiddlewaretoken' Type ='ResponseBased'*/
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

	web_url("Log In", 
		"URL=http://{host}:{port}/login/?next=/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	lr_end_transaction("UC07_TR01_open_login_page",LR_AUTO);

	web_add_cookie("SRCHUID=V=2&GUID=EB60E1DB538A4CCEAB5E486D725A4F88&dmnchg=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("_EDGE_V=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("MUID=28F54B3AE71C6D481DAD5BCDE6CE6C8A; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20220214; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHHPGUSR=SRCHLANG=ru; DOMAIN=iecvlist.microsoft.com");

	lr_think_time(9);

	web_url("versionlist.xml", 
		"URL=https://iecvlist.microsoft.com/ie11blocklist/1401746408/versionlist.xml", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t8.inf", 
		LAST);

	lr_start_transaction("UC07_TR02_user_login");

	web_submit_data("login",
		"Action=http://{host}:{port}/login/",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/login/?next=/",
		"Snapshot=t9.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=username", "Value=testuser1", ENDITEM,
		"Name=password", "Value=1alphabravo2", ENDITEM,
		"Name=next", "Value=/", ENDITEM,
		"Name=csrfmiddlewaretoken", "Value={csrfmiddlewaretoken}", ENDITEM,
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");
	
	web_reg_save_param_ex(
    "ParamName=id_list",
    "LB= \"id\":",
    "RB=, \"priority\": ",
    "Ordinal=All",
    SEARCH_FILTERS,
    "Scope=Body",
    LAST);

	web_url("eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbMSwgMl19LCAic29ydGluZyI6ICJjcmVhdGVkIiwgInNlYXJjaF9zdHJpbmciOiAiIiwgInNvcnRyZXZlcnNlIjogZmFsc2V9", 
		"URL=http://{host}:{port}/datatables_ticket_list/eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbMSwgMl19LCAic29ydGluZyI6ICJjcmVhdGVkIiwgInNlYXJjaF9zdHJpbmciOiAiIiwgInNvcnRyZXZlcnNlIjogZmFsc2V9?draw=1&columns%5B0%5D%5Bdata%5D=id&columns%5B0%5D%5Bname%5D=&columns%5B0%5D%5Bsearchable%5D=true&columns%5B0%5D%5Borderable%5D=false&columns%5B0%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B0%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B1%5D%5Bdata%5D=ticket&columns%5B1%5D%5Bname%5D=&columns%5B1%5D%5Bsearchable%5D=true&"
		"columns%5B1%5D%5Borderable%5D=true&columns%5B1%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B1%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B2%5D%5Bdata%5D=priority&columns%5B2%5D%5Bname%5D=&columns%5B2%5D%5Bsearchable%5D=true&columns%5B2%5D%5Borderable%5D=true&columns%5B2%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B2%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B3%5D%5Bdata%5D=queue&columns%5B3%5D%5Bname%5D=&columns%5B3%5D%5Bsearchable%5D=true&columns%5B3%5D%5Borderable%5D=true&columns%5B3%5D%5Bsearch%5D%5Bvalue%5D=&"
		"columns%5B3%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B4%5D%5Bdata%5D=status&columns%5B4%5D%5Bname%5D=&columns%5B4%5D%5Bsearchable%5D=true&columns%5B4%5D%5Borderable%5D=true&columns%5B4%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B4%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B5%5D%5Bdata%5D=created&columns%5B5%5D%5Bname%5D=&columns%5B5%5D%5Bsearchable%5D=true&columns%5B5%5D%5Borderable%5D=true&columns%5B5%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B5%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B6%5D%5Bdata%5D=due_date"
		"&columns%5B6%5D%5Bname%5D=&columns%5B6%5D%5Bsearchable%5D=true&columns%5B6%5D%5Borderable%5D=true&columns%5B6%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B6%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B7%5D%5Bdata%5D=assigned_to&columns%5B7%5D%5Bname%5D=&columns%5B7%5D%5Bsearchable%5D=true&columns%5B7%5D%5Borderable%5D=true&columns%5B7%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B7%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B8%5D%5Bdata%5D=submitter&columns%5B8%5D%5Bname%5D=&columns%5B8%5D%5Bsearchable%5D=true&"
		"columns%5B8%5D%5Borderable%5D=true&columns%5B8%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B8%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B9%5D%5Bdata%5D=time_spent&columns%5B9%5D%5Bname%5D=&columns%5B9%5D%5Bsearchable%5D=true&columns%5B9%5D%5Borderable%5D=true&columns%5B9%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B9%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B10%5D%5Bdata%5D=kbitem&columns%5B10%5D%5Bname%5D=&columns%5B10%5D%5Bsearchable%5D=true&columns%5B10%5D%5Borderable%5D=true&"
		"columns%5B10%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B10%5D%5Bsearch%5D%5Bregex%5D=false&order%5B0%5D%5Bcolumn%5D=0&order%5B0%5D%5Bdir%5D=asc&start=0&length=25&search%5Bvalue%5D=&search%5Bregex%5D=false&_=1646393603696", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC07_TR02_user_login",LR_AUTO);

	return 0;
}
