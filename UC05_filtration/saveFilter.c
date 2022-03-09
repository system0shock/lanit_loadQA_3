saveFilter()
{
	lr_think_time(50);

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

	web_url("tickets", 
		"URL=http://{host}:{port}/tickets/?sortx=created&{filters}&status=1&status=2&date_from=&date_to=&q=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_end_transaction("UC05_TR03_add_filter",LR_AUTO);

	lr_start_transaction("UC05_TR04_save_query");

	web_submit_data("save_query",
		"Action=http://{host}:{port}/save_query/",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/tickets/?sortx=created&{filters}&status=1&status=2&date_from=&date_to=&q=",
		"Snapshot=t10.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrfmiddlewaretoken", "Value={csrfmiddlewaretoken_1}", ENDITEM,
		//"Name=query_encoded", "Value=eyJmaWx0ZXJpbmciOiB7InF1ZXVlX19pZF9faW4iOiBbMV0sICJhc3NpZ25lZF90b19faWRfX2luIjogWzJdLCAic3RhdHVzX19pbiI6IFsxLCAyXX0sICJmaWx0ZXJpbmdfb3IiOiB7InF1ZXVlX19pZF9faW4iOiBbMV0sICJhc3NpZ25lZF90b19faWRfX2luIjogWzJdLCAic3RhdHVzX19pbiI6IFsxLCAyXX0sICJzb3J0aW5nIjogImNyZWF0ZWQiLCAic29ydHJldmVyc2UiOiBudWxsLCAic2VhcmNoX3N0cmluZyI6ICIifQ==", ENDITEM,
		"Name=title", "Value=1", ENDITEM,
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_end_transaction("UC05_TR04_save_query",LR_AUTO);

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

