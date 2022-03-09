Action()
{

	lr_think_time(60);

	lr_start_transaction("TR03_show_duplicates");

	web_url("tickets", 
		"URL=http://{host}:{port}/tickets/?sortx=created&status=5&date_from=&date_to=&q=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbNV19LCAiZmlsdGVyaW5nX29yIjogeyJzdGF0dXNfX2luIjogWzVdfSwgInNvcnRpbmciOiAiY3JlYXRlZCIsICJzb3J0cmV2ZXJzZSI6IG51bGwsICJzZWFyY2hfc3RyaW5nIjogIiJ9", 
		"URL=http://{host}:{port}/datatables_ticket_list/eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbNV19LCAiZmlsdGVyaW5nX29yIjogeyJzdGF0dXNfX2luIjogWzVdfSwgInNvcnRpbmciOiAiY3JlYXRlZCIsICJzb3J0cmV2ZXJzZSI6IG51bGwsICJzZWFyY2hfc3RyaW5nIjogIiJ9?draw=1&columns%5B0%5D%5Bdata%5D=id&columns%5B0%5D%5Bname%5D=&columns%5B0%5D%5Bsearchable%5D=true&columns%5B0%5D%5Borderable%5D=false&columns%5B0%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B0%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B1%5D%5Bdata%5D=ticket&"
		"columns%5B1%5D%5Bname%5D=&columns%5B1%5D%5Bsearchable%5D=true&columns%5B1%5D%5Borderable%5D=true&columns%5B1%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B1%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B2%5D%5Bdata%5D=priority&columns%5B2%5D%5Bname%5D=&columns%5B2%5D%5Bsearchable%5D=true&columns%5B2%5D%5Borderable%5D=true&columns%5B2%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B2%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B3%5D%5Bdata%5D=queue&columns%5B3%5D%5Bname%5D=&columns%5B3%5D%5Bsearchable%5D=true&"
		"columns%5B3%5D%5Borderable%5D=true&columns%5B3%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B3%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B4%5D%5Bdata%5D=status&columns%5B4%5D%5Bname%5D=&columns%5B4%5D%5Bsearchable%5D=true&columns%5B4%5D%5Borderable%5D=true&columns%5B4%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B4%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B5%5D%5Bdata%5D=created&columns%5B5%5D%5Bname%5D=&columns%5B5%5D%5Bsearchable%5D=true&columns%5B5%5D%5Borderable%5D=true&columns%5B5%5D%5Bsearch%5D%5Bvalue%5D=&"
		"columns%5B5%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B6%5D%5Bdata%5D=due_date&columns%5B6%5D%5Bname%5D=&columns%5B6%5D%5Bsearchable%5D=true&columns%5B6%5D%5Borderable%5D=true&columns%5B6%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B6%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B7%5D%5Bdata%5D=assigned_to&columns%5B7%5D%5Bname%5D=&columns%5B7%5D%5Bsearchable%5D=true&columns%5B7%5D%5Borderable%5D=true&columns%5B7%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B7%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B8%5D%5Bdata%5D="
		"submitter&columns%5B8%5D%5Bname%5D=&columns%5B8%5D%5Bsearchable%5D=true&columns%5B8%5D%5Borderable%5D=true&columns%5B8%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B8%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B9%5D%5Bdata%5D=time_spent&columns%5B9%5D%5Bname%5D=&columns%5B9%5D%5Bsearchable%5D=true&columns%5B9%5D%5Borderable%5D=true&columns%5B9%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B9%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B10%5D%5Bdata%5D=kbitem&columns%5B10%5D%5Bname%5D=&columns%5B10%5D%5Bsearchable%5D=true"
		"&columns%5B10%5D%5Borderable%5D=true&columns%5B10%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B10%5D%5Bsearch%5D%5Bregex%5D=false&order%5B0%5D%5Bcolumn%5D=0&order%5B0%5D%5Bdir%5D=asc&start=0&length=25&search%5Bvalue%5D=&search%5Bregex%5D=false&_=1646405862208", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host}:{port}/tickets/?sortx=created&status=5&date_from=&date_to=&q=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR03_show_duplicates",LR_AUTO);

	lr_think_time(53);

	web_url("tickets_2", 
		"URL=http://{host}:{port}/tickets/?sortx=priority&status=5&date_from=&date_to=&q=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/?sortx=created&status=5&date_from=&date_to=&q=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbNV19LCAiZmlsdGVyaW5nX29yIjogeyJzdGF0dXNfX2luIjogWzVdfSwgInNvcnRpbmciOiAiY3JlYXRlZCIsICJzb3J0cmV2ZXJzZSI6IG51bGwsICJzZWFyY2hfc3RyaW5nIjogIiJ9_2", 
		"URL=http://{host}:{port}/datatables_ticket_list/eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbNV19LCAiZmlsdGVyaW5nX29yIjogeyJzdGF0dXNfX2luIjogWzVdfSwgInNvcnRpbmciOiAiY3JlYXRlZCIsICJzb3J0cmV2ZXJzZSI6IG51bGwsICJzZWFyY2hfc3RyaW5nIjogIiJ9?draw=1&columns%5B0%5D%5Bdata%5D=id&columns%5B0%5D%5Bname%5D=&columns%5B0%5D%5Bsearchable%5D=true&columns%5B0%5D%5Borderable%5D=false&columns%5B0%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B0%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B1%5D%5Bdata%5D=ticket&"
		"columns%5B1%5D%5Bname%5D=&columns%5B1%5D%5Bsearchable%5D=true&columns%5B1%5D%5Borderable%5D=true&columns%5B1%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B1%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B2%5D%5Bdata%5D=priority&columns%5B2%5D%5Bname%5D=&columns%5B2%5D%5Bsearchable%5D=true&columns%5B2%5D%5Borderable%5D=true&columns%5B2%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B2%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B3%5D%5Bdata%5D=queue&columns%5B3%5D%5Bname%5D=&columns%5B3%5D%5Bsearchable%5D=true&"
		"columns%5B3%5D%5Borderable%5D=true&columns%5B3%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B3%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B4%5D%5Bdata%5D=status&columns%5B4%5D%5Bname%5D=&columns%5B4%5D%5Bsearchable%5D=true&columns%5B4%5D%5Borderable%5D=true&columns%5B4%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B4%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B5%5D%5Bdata%5D=created&columns%5B5%5D%5Bname%5D=&columns%5B5%5D%5Bsearchable%5D=true&columns%5B5%5D%5Borderable%5D=true&columns%5B5%5D%5Bsearch%5D%5Bvalue%5D=&"
		"columns%5B5%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B6%5D%5Bdata%5D=due_date&columns%5B6%5D%5Bname%5D=&columns%5B6%5D%5Bsearchable%5D=true&columns%5B6%5D%5Borderable%5D=true&columns%5B6%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B6%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B7%5D%5Bdata%5D=assigned_to&columns%5B7%5D%5Bname%5D=&columns%5B7%5D%5Bsearchable%5D=true&columns%5B7%5D%5Borderable%5D=true&columns%5B7%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B7%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B8%5D%5Bdata%5D="
		"submitter&columns%5B8%5D%5Bname%5D=&columns%5B8%5D%5Bsearchable%5D=true&columns%5B8%5D%5Borderable%5D=true&columns%5B8%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B8%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B9%5D%5Bdata%5D=time_spent&columns%5B9%5D%5Bname%5D=&columns%5B9%5D%5Bsearchable%5D=true&columns%5B9%5D%5Borderable%5D=true&columns%5B9%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B9%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B10%5D%5Bdata%5D=kbitem&columns%5B10%5D%5Bname%5D=&columns%5B10%5D%5Bsearchable%5D=true"
		"&columns%5B10%5D%5Borderable%5D=true&columns%5B10%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B10%5D%5Bsearch%5D%5Bregex%5D=false&order%5B0%5D%5Bcolumn%5D=0&order%5B0%5D%5Bdir%5D=asc&start=0&length=25&search%5Bvalue%5D=&search%5Bregex%5D=false&_=1646405915713", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host}:{port}/tickets/?sortx=priority&status=5&date_from=&date_to=&q=", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(33);

	lr_start_transaction("TR05_open_highest_priority_ticket");

/*Correlation comment - Do not change!  Original value='K37gQe9m791ZMq7QBvh1Nd43fS5P1GRtOxlHn2TfXkDlYjV93bvKuRhRtX9jgFFl' Name ='csrfmiddlewaretoken_1' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=csrfmiddlewaretoken_1",
		"TagName=input",
		"Extract=value",
		"Name=csrfmiddlewaretoken",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_url("tickets_3", 
		"URL=http://{host}:{port}/tickets/?sortx=created&status=5&date_from=&date_to=&q=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/?sortx=priority&status=5&date_from=&date_to=&q=", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbNV19LCAiZmlsdGVyaW5nX29yIjogeyJzdGF0dXNfX2luIjogWzVdfSwgInNvcnRpbmciOiAiY3JlYXRlZCIsICJzb3J0cmV2ZXJzZSI6IG51bGwsICJzZWFyY2hfc3RyaW5nIjogIiJ9_3", 
		"URL=http://{host}:{port}/datatables_ticket_list/eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbNV19LCAiZmlsdGVyaW5nX29yIjogeyJzdGF0dXNfX2luIjogWzVdfSwgInNvcnRpbmciOiAiY3JlYXRlZCIsICJzb3J0cmV2ZXJzZSI6IG51bGwsICJzZWFyY2hfc3RyaW5nIjogIiJ9?draw=1&columns%5B0%5D%5Bdata%5D=id&columns%5B0%5D%5Bname%5D=&columns%5B0%5D%5Bsearchable%5D=true&columns%5B0%5D%5Borderable%5D=false&columns%5B0%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B0%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B1%5D%5Bdata%5D=ticket&"
		"columns%5B1%5D%5Bname%5D=&columns%5B1%5D%5Bsearchable%5D=true&columns%5B1%5D%5Borderable%5D=true&columns%5B1%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B1%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B2%5D%5Bdata%5D=priority&columns%5B2%5D%5Bname%5D=&columns%5B2%5D%5Bsearchable%5D=true&columns%5B2%5D%5Borderable%5D=true&columns%5B2%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B2%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B3%5D%5Bdata%5D=queue&columns%5B3%5D%5Bname%5D=&columns%5B3%5D%5Bsearchable%5D=true&"
		"columns%5B3%5D%5Borderable%5D=true&columns%5B3%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B3%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B4%5D%5Bdata%5D=status&columns%5B4%5D%5Bname%5D=&columns%5B4%5D%5Bsearchable%5D=true&columns%5B4%5D%5Borderable%5D=true&columns%5B4%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B4%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B5%5D%5Bdata%5D=created&columns%5B5%5D%5Bname%5D=&columns%5B5%5D%5Bsearchable%5D=true&columns%5B5%5D%5Borderable%5D=true&columns%5B5%5D%5Bsearch%5D%5Bvalue%5D=&"
		"columns%5B5%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B6%5D%5Bdata%5D=due_date&columns%5B6%5D%5Bname%5D=&columns%5B6%5D%5Bsearchable%5D=true&columns%5B6%5D%5Borderable%5D=true&columns%5B6%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B6%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B7%5D%5Bdata%5D=assigned_to&columns%5B7%5D%5Bname%5D=&columns%5B7%5D%5Bsearchable%5D=true&columns%5B7%5D%5Borderable%5D=true&columns%5B7%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B7%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B8%5D%5Bdata%5D="
		"submitter&columns%5B8%5D%5Bname%5D=&columns%5B8%5D%5Bsearchable%5D=true&columns%5B8%5D%5Borderable%5D=true&columns%5B8%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B8%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B9%5D%5Bdata%5D=time_spent&columns%5B9%5D%5Bname%5D=&columns%5B9%5D%5Bsearchable%5D=true&columns%5B9%5D%5Borderable%5D=true&columns%5B9%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B9%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B10%5D%5Bdata%5D=kbitem&columns%5B10%5D%5Bname%5D=&columns%5B10%5D%5Bsearchable%5D=true"
		"&columns%5B10%5D%5Borderable%5D=true&columns%5B10%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B10%5D%5Bsearch%5D%5Bregex%5D=false&order%5B0%5D%5Bcolumn%5D=0&order%5B0%5D%5Bdir%5D=asc&start=0&length=25&search%5Bvalue%5D=&search%5Bregex%5D=false&_=1646405949583", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host}:{port}/tickets/?sortx=created&status=5&date_from=&date_to=&q=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR05_open_highest_priority_ticket",LR_AUTO);

	lr_start_transaction("TR07_select_and_delete_ticket");

	web_submit_data("update",
		"Action=http://{host}:{port}/tickets/update/",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/tickets/?sortx=created&status=5&date_from=&date_to=&q=",
		"Snapshot=t16.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrfmiddlewaretoken", "Value={csrfmiddlewaretoken_1}", ENDITEM,
		"Name=ticketTable_length", "Value=25", ENDITEM,
		"Name=ticket_id", "Value=6", ENDITEM,
		"Name=action", "Value=delete", ENDITEM,
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbMSwgMl19LCAic29ydGluZyI6ICJjcmVhdGVkIiwgInNlYXJjaF9zdHJpbmciOiAiIiwgInNvcnRyZXZlcnNlIjogZmFsc2V9_2", 
		"URL=http://{host}:{port}/datatables_ticket_list/eyJmaWx0ZXJpbmciOiB7InN0YXR1c19faW4iOiBbMSwgMl19LCAic29ydGluZyI6ICJjcmVhdGVkIiwgInNlYXJjaF9zdHJpbmciOiAiIiwgInNvcnRyZXZlcnNlIjogZmFsc2V9?draw=1&columns%5B0%5D%5Bdata%5D=id&columns%5B0%5D%5Bname%5D=&columns%5B0%5D%5Bsearchable%5D=true&columns%5B0%5D%5Borderable%5D=false&columns%5B0%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B0%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B1%5D%5Bdata%5D=ticket&columns%5B1%5D%5Bname%5D=&columns%5B1%5D%5Bsearchable%5D=true&"
		"columns%5B1%5D%5Borderable%5D=true&columns%5B1%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B1%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B2%5D%5Bdata%5D=priority&columns%5B2%5D%5Bname%5D=&columns%5B2%5D%5Bsearchable%5D=true&columns%5B2%5D%5Borderable%5D=true&columns%5B2%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B2%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B3%5D%5Bdata%5D=queue&columns%5B3%5D%5Bname%5D=&columns%5B3%5D%5Bsearchable%5D=true&columns%5B3%5D%5Borderable%5D=true&columns%5B3%5D%5Bsearch%5D%5Bvalue%5D=&"
		"columns%5B3%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B4%5D%5Bdata%5D=status&columns%5B4%5D%5Bname%5D=&columns%5B4%5D%5Bsearchable%5D=true&columns%5B4%5D%5Borderable%5D=true&columns%5B4%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B4%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B5%5D%5Bdata%5D=created&columns%5B5%5D%5Bname%5D=&columns%5B5%5D%5Bsearchable%5D=true&columns%5B5%5D%5Borderable%5D=true&columns%5B5%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B5%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B6%5D%5Bdata%5D=due_date"
		"&columns%5B6%5D%5Bname%5D=&columns%5B6%5D%5Bsearchable%5D=true&columns%5B6%5D%5Borderable%5D=true&columns%5B6%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B6%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B7%5D%5Bdata%5D=assigned_to&columns%5B7%5D%5Bname%5D=&columns%5B7%5D%5Bsearchable%5D=true&columns%5B7%5D%5Borderable%5D=true&columns%5B7%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B7%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B8%5D%5Bdata%5D=submitter&columns%5B8%5D%5Bname%5D=&columns%5B8%5D%5Bsearchable%5D=true&"
		"columns%5B8%5D%5Borderable%5D=true&columns%5B8%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B8%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B9%5D%5Bdata%5D=time_spent&columns%5B9%5D%5Bname%5D=&columns%5B9%5D%5Bsearchable%5D=true&columns%5B9%5D%5Borderable%5D=true&columns%5B9%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B9%5D%5Bsearch%5D%5Bregex%5D=false&columns%5B10%5D%5Bdata%5D=kbitem&columns%5B10%5D%5Bname%5D=&columns%5B10%5D%5Bsearchable%5D=true&columns%5B10%5D%5Borderable%5D=true&"
		"columns%5B10%5D%5Bsearch%5D%5Bvalue%5D=&columns%5B10%5D%5Bsearch%5D%5Bregex%5D=false&order%5B0%5D%5Bcolumn%5D=0&order%5B0%5D%5Bdir%5D=asc&start=0&length=25&search%5Bvalue%5D=&search%5Bregex%5D=false&_=1646405988224", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR07_select_and_delete_ticket",LR_AUTO);

	lr_start_transaction("TR08_logout");

	web_url("logout", 
		"URL=http://{host}:{port}/logout/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("TR08_logout",LR_AUTO);

	return 0;
}