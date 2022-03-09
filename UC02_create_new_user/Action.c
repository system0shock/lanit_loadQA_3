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
char *filePath="..\Parametres\users.csv";
int ID;

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

//static char *rand_string(char *str, size_t size)
//{
//    
//    if (size) {
//        --size;
//        for (n = 0; n < size; n++) {
//            int key = rand() % (int) (sizeof charset - 1);
//            str[n] = charset[key];
//        }
//        str[size] = '\0';
//    }
//    return str;
//}


Action()
{
	
	lr_start_transaction("UC02_TR01_open_login_form");
    //get cookie . csrf token, sessionid
    web_reg_save_param_ex(
    	"ParamName=csrftoken",
    	"LB=csrftoken=",
    	"RB=;",
    	"Ordinal=all",
    	"Notfound=warning",
    	SEARCH_FILTERS,
    	"Scope=Cookies",
    	LAST);
    
    //get from html middle csrf token
    
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
	
	lr_start_transaction("UC02_TR02_admin_login");

	
	
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
    	"ParamName=sessionId",
    	"LB=sessionid=",
    	"RB=;",
    	"Ordinal=all",
    	"Notfound=warning",
    	SEARCH_FILTERS,
    	"Scope=Cookies",
    	LAST);
	web_add_cookie("csrftoken={csrftoken_1}; DOMAIN={host}");
	
	web_submit_data("login_2",
		"Action=http://{host}:{port}/login/",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/login/?next=/",
		"Snapshot=t3.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=username", "Value=admin", ENDITEM,
		"Name=password", "Value=admindev", ENDITEM,
		"Name=next", "Value=/", ENDITEM,
		"Name=csrfmiddlewaretoken", "Value={middlecsrftoken_1}", ENDITEM,
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");
	
	lr_end_transaction("UC02_TR02_admin_login",LR_AUTO);
	
	lr_start_transaction("UC02_TR03_open_system_settings");
	
//	web_add_cookie("sessionid={sessionId_1}; DOMAIN={host}");
//	web_add_cookie("csrftoken={csrftoken_2}; DOMAIN={host}");

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
		"Url=/static/admin/css/fonts.css", ENDITEM, 
		"Url=/static/admin/fonts/Roboto-Bold-webfont.woff", ENDITEM, 
		"Url=/static/admin/fonts/Roboto-Light-webfont.woff", ENDITEM, 
		"Url=/static/admin/fonts/Roboto-Regular-webfont.woff", ENDITEM, 
		"Url=/static/admin/img/sorting-icons.svg", ENDITEM, 
		"Url=/static/admin/img/tooltag-add.svg", ENDITEM, 
		"Url=/static/admin/img/icon-addlink.svg", ENDITEM, 
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
		"Url=/static/admin/css/widgets.css", ENDITEM, 
		LAST);

	lr_end_transaction("UC02_TR05_press_add_user_button",LR_AUTO);
	
	lr_start_transaction("UC02_TR06_new_user_creation");
	
	new_username=random_word(8);
	lr_save_string(new_username,"new_login");
    lr_output_message("%s",new_username);
    
//    buff[32]='\0';
    
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
//		"URL=/static/admin/img/icon-deletelink.svg", "Referer=http://{host}:{port}/admin/auth/user/{userID}/change/", ENDITEM,
		LAST);

	lr_end_transaction("UC02_TR06_new_user_creation",LR_AUTO);

	lr_start_transaction("UC02_TR07_enable_staff_status");

	
	web_submit_data("change",
		"Action=http://{host}:{port}/admin/auth/user/{userID_1}/change/",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{host}:{port}/admin/auth/user/{userID_1}/change/",
		"Snapshot=t9.inf",
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
		"Name=_save", "Value=Save", ENDITEM,
		LAST);
	

	lr_end_transaction("UC02_TR07_enable_staff_status",LR_AUTO);
	
	//try save new user to users.csv 
	
	ID=atoi(lr_eval_string("userID"))+1;
	lr_output_message("%s",new_password);
	lr_output_message("%s",new_username);
	file = fopen(filePath, "a+");
//	fprintf(file,"username, password, ID\n");
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
