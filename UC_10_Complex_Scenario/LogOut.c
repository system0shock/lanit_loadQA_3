LogOut()
{
	
		lr_start_transaction("Logout");

	web_url("logout", 
		"URL=http://{host}:{port}/logout/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);
	return 0;
}
