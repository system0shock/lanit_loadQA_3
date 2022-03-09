vuser_init()
{
		web_url("{host}:{port}", 
		"URL=http://{host}:{port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/helpdesk/helpdesk-customize.css", ENDITEM, 
		"Url=/static/helpdesk/vendor/fontawesome-free/webfonts/fa-regular-400.eot?", ENDITEM, 
		"Url=/static/helpdesk/vendor/fontawesome-free/webfonts/fa-solid-900.eot?", ENDITEM, 
		"Url=/static/helpdesk/vendor/fontawesome-free/webfonts/fa-regular-400.woff", ENDITEM, 
		"Url=/static/helpdesk/vendor/fontawesome-free/webfonts/fa-solid-900.woff", ENDITEM, 
		LAST);
	return 0;
}
