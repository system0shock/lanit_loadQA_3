char buff[32] = "";
char buff2[32] = "";
int id = 3;
FILE *file;
long FileVarriable;  
//char FileLocation[1024] = "user.csv"; 
char *new_username;
char *new_password;
//str=lr_eval_string("param");
char logpass[];
char *filePath="..\\Parametres\\users.csv";
long int ID;
int HTTP_rc;

char* random_word(int length)
{ 

  int r,i;
  char c;
  

for (i = 0; i < length; i++)
{
    r = rand() % 25 + 65;
    c = (char)r;
    buff[i] = c;
    //printf("%c", c);
   
}

////lr_save_string(buff, param_name);
return buff;
}

char* random_word2(int length)
{ 

  int r,i;
  char c;
  

for (i = 0; i < length; i++)
{
    r = rand() % 25 + 65;
    c = (char)r;
    buff2[i] = c;
    //printf("%c", c);
   
}

////lr_save_string(buff, param_name);
return buff2;
}



Action()
{
	
	lr_start_transaction("UC02_TR01_open_login_form");

    web_reg_save_param_ex(
    	"ParamName=csrftoken",
    	"LB=csrftoken=",
    	"RB=;",
    	"Ordinal=all",
    	"Notfound=warning",
    	SEARCH_FILTERS,
    	"Scope=Cookies",
    	LAST);
    
        web_reg_save_param_ex(
    	"ParamName=middlecsrftoken",
    	"LB=csrfmiddlewaretoken\" value=\"",
    	"RB=\">",
    	"Ordinal=all",
    	"Notfound=warning",
    	LAST);
    
	web_url("login", 
		"URL=http://{host}:{port}/login/?next=/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
    
	lr_end_transaction("UC02_TR01_open_login_form",LR_AUTO);
	
	//check csrf token without warning
	
	lr_start_transaction("UC02_TR02_user_login");

	
	
	//get new csrf and sessionid
	    web_reg_save_param_ex(
    	"ParamName=csrftoken",
    	"LB=csrftoken=",
    	"RB=;",
    	"Ordinal=all",
    	"Notfound=warning",
    	SEARCH_FILTERS,
    	"Scope=Cookies",
    	LAST);
	    
	    web_reg_save_param_ex(
    	"ParamName=query_encoded",
    	"LB=encoded\' value=\'",
    	"RB=\'",
    	"Ordinal=all",
    	"Notfound=warning",
    	LAST);
		
	    web_reg_save_param_ex(
    	"ParamName=sessionId",
    	"LB=sessionid=",
    	"RB=;",
    	"Ordinal=all",
    	"Notfound=warning",
    	SEARCH_FILTERS,
    	"Scope=Cookies",
    	LAST);
	web_add_cookie("csrftoken={csrftoken_1}; DOMAIN={host}");
	HTTP_rc = web_get_int_property(HTTP_INFO_RETURN_CODE);
	web_submit_data("login_2",
		"Action=http://{host}:{port}/login/",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/login/?next=/",
		"Snapshot=t3.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={pass}", ENDITEM,
		"Name=next", "Value=/", ENDITEM,
		"Name=csrfmiddlewaretoken", "Value={middlecsrftoken_1}", ENDITEM,
		LAST);
		
	HTTP_rc = web_get_int_property(HTTP_INFO_RETURN_CODE);
	if (HTTP_rc < 400){
		lr_log_message("auth ok");		
		lr_end_transaction("UC02_TR02_user_login",LR_PASS);
	} else {
		lr_log_message("auth fail");
		lr_end_transaction("UC02_TR02_user_login",LR_FAIL);
	}

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");
	
	
	lr_start_transaction("UC02_TR03_open_system_settings");
	

    	web_url("system_settings", 
		"URL=http://{host}:{port}/system_settings/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/tickets/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("UC02_TR03_open_system_settings",LR_AUTO);
	
	
	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/
   lr_start_transaction("UC02_TR04_open_maintain_users_page");
	web_url("Maintain Users", 
		"URL=http://{host}:{port}/admin/auth/user/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/system_settings/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		EXTRARES,  
		LAST);

	lr_end_transaction("UC02_TR04_open_maintain_users_page",LR_AUTO);
	
		lr_start_transaction("UC02_TR05_press_add_user_button");
        //get from html middle csrf token
    
        web_reg_save_param_ex(
    	"ParamName=middlecsrftokennew",
    	"LB=csrfmiddlewaretoken\" value=\"",
    	"RB=\">",
    	"Ordinal=all",
    	"Notfound=warning",
    	LAST);
        
        
	web_url("Add", 
		"URL=http://{host}:{port}/admin/auth/user/add/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/admin/auth/user/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		EXTRARES,  
		LAST);

	lr_end_transaction("UC02_TR05_press_add_user_button",LR_AUTO);
	
	lr_start_transaction("UC02_TR06_new_user_creation");
	
	new_username=random_word(8);
	lr_save_string(new_username,"new_login");
    lr_output_message("%s",new_username);
    
    
    new_password=random_word2(12);
    lr_save_string(new_password,"new_pass");
    lr_output_message("%s",new_password);
    
    web_set_max_html_param_len("15000");
	web_reg_save_param_ex(
    "ParamName=userID",
    "LB= \/admin\/auth\/user\/",
    "RB=\/change\/",
    "Ordinal=All",
//    SEARCH_FILTERS,
//    "Scope=Body",
    LAST);

	web_submit_data("add",
		"Action=http://{host}:{port}/admin/auth/user/add/",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/admin/auth/user/add/",
		"Snapshot=t8.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrfmiddlewaretoken", "Value={middlecsrftokennew_1}", ENDITEM,
		"Name=username", "Value={new_login}", ENDITEM,
		"Name=password1", "Value={new_pass}", ENDITEM,
		"Name=password2", "Value={new_pass}", ENDITEM,
		"Name=_save", "Value=Save", ENDITEM,
		EXTRARES,
		LAST);

	lr_end_transaction("UC02_TR06_new_user_creation",LR_AUTO);

	lr_start_transaction("UC02_TR07_enable_staff_status");

	web_reg_find("Fail=NotFound",
		"Text={new_login}",
		LAST);
	
	web_submit_data("change",
		"Action=http://{host}:{port}/admin/auth/user/{userID_1}/change/", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/admin/auth/user/{userID_1}/change/", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=csrfmiddlewaretoken", "Value={middlecsrftokennew_1}", ENDITEM, 
		"Name=username", "Value={new_login}", ENDITEM, 
		"Name=first_name", "Value=", ENDITEM, 
		"Name=last_name", "Value=", ENDITEM, 
		"Name=email", "Value=", ENDITEM, 
		"Name=is_active", "Value=on", ENDITEM, 
		"Name=is_staff", "Value=on", ENDITEM, 
		"Name=last_login_0", "Value=", ENDITEM, 
		"Name=last_login_1", "Value=", ENDITEM, 
		"Name=date_joined_0", "Value=2022-03-17", ENDITEM, 
		"Name=date_joined_1", "Value=20:07:02", ENDITEM, 
		"Name=initial-date_joined_0", "Value=2022-03-17", ENDITEM, 
		"Name=initial-date_joined_1", "Value=20:07:02", ENDITEM, 
		"Name=_save", "Value=Save", ENDITEM, 
		LAST);
	

	lr_end_transaction("UC02_TR07_enable_staff_status",LR_AUTO);
	



	

	ID=atoi(lr_eval_string("{userID_1}"));
	
	lr_output_message("%d",ID);
	lr_output_message("%s",new_password);
	lr_output_message("%s",new_username);
	file = fopen(filePath, "a+");

	fprintf(file,"%s, %s, %d\n", new_username, new_password, ID);
	fclose(file);
	
	

    
    lr_output_message("Successfully wrote File");
    
 
    	
	lr_start_transaction("UC02_TR08_logout");

	web_url("Log out", 
		"URL=http://{host}:{port}/admin/logout/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host}:{port}/admin/auth/user/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC02_TR08_logout",LR_AUTO);
	
	return 0;
}
