#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


/********** PLEASE CHANGE THIS *************************/
const char* ssid     = "<ENTER YOUR WIFI SSID>";
const char* password = "<ENTER YOUR PASSWORD>";

ESP8266WebServer server(80);

uint8_t LEDPin = D7;
bool LEDStatus = LOW;

uint8_t buzzerPin = D1;
bool buzzerStatus = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/toggleLED", updateLED);
  server.on("/toggleBuzzer", updateBuzzerSound);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
}

void handleRoot() {
  server.send(200, "text/html", prepareHTML());
}

void updateLED() {
  String ledStatusParam = server.arg("ledStatus");
  if (ledStatusParam == "ON")
    LEDStatus =  HIGH;
  else
    LEDStatus =  LOW;
  digitalWrite(LEDPin, LEDStatus);

  server.send(200, "text/plain", "Success!");
}

void updateBuzzerSound() {
  String buzzerStatusParam = server.arg("buzzerStatus");
  if (buzzerStatusParam == "ON")
    buzzerStatus =  HIGH;
  else
    buzzerStatus =  LOW;

  if (buzzerStatus)
    tone(buzzerPin, 1200);
  else
    noTone(buzzerPin);

  server.send(200, "text/plain", "Success!");
}

void handleNotFound() {
  server.send(404, "text/plain", "Not found");
}

String prepareHTML() {
  // BuildMyString.com generated code. Please enjoy your string responsibly.

  String html = "<!DOCTYPE html>\n"
                "<html>\n"
                "  <head>\n"
                "   <meta charset=\"UTF-8\">\n"
                "   <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
                "   <title>NodeMCU ESP8266 Web Server</title>\n"
                "   <style>\n"
                "     /* Copyright 2014 Owen Versteeg; MIT licensed */body,textarea,input,select{background:0;border-radius:0;font:16px sans-serif;margin:0}.smooth{transition:all .2s}.btn,.nav a{text-decoration:none}.container{margin:0 20px;width:auto}label>*{display:inline}form>*{display:block;margin-bottom:10px}.btn{background:#999;border-radius:6px;border:0;color:#fff;cursor:pointer;display:inline-block;margin:2px 0;padding:12px 30px 14px}.btn:hover{background:#888}.btn:active,.btn:focus{background:#777}.btn-a{background:#0ae}.btn-a:hover{background:#09d}.btn-a:active,.btn-a:focus{background:#08b}.btn-b{background:#3c5}.btn-b:hover{background:#2b4}.btn-b:active,.btn-b:focus{background:#2a4}.btn-c{background:#d33}.btn-c:hover{background:#c22}.btn-c:active,.btn-c:focus{background:#b22}.btn-sm{border-radius:4px;padding:10px 14px 11px}.row{margin:1% 0;overflow:auto}.col{float:left}.table,.c12{width:100%}.c11{width:91.66%}.c10{width:83.33%}.c9{width:75%}.c8{width:66.66%}.c7{width:58.33%}.c6{width:50%}.c5{width:41.66%}.c4{width:33.33%}.c3{width:25%}.c2{width:16.66%}.c1{width:8.33%}h1{font-size:3em}.btn,h2{font-size:2em}.ico{font:33px Arial Unicode MS,Lucida Sans Unicode}.addon,.btn-sm,.nav,textarea,input,select{outline:0;font-size:14px}textarea,input,select{padding:8px;border:1px solid #ccc}textarea:focus,input:focus,select:focus{border-color:#5ab}textarea,input[type=text]{-webkit-appearance:none;width:13em}.addon{padding:8px 12px;box-shadow:0 0 0 1px #ccc}.nav,.nav .current,.nav a:hover{background:#000;color:#fff}.nav{height:24px;padding:11px 0 15px}.nav a{color:#aaa;padding-right:1em;position:relative;top:-1px}.nav .pagename{font-size:22px;top:1px}.btn.btn-close{background:#000;float:right;font-size:25px;margin:-54px 7px;display:none}@media(min-width:1310px){.container{margin:auto;width:1270px}}@media(max-width:870px){.row .col{width:100%}}@media(max-width:500px){.btn.btn-close{display:block}.nav{overflow:hidden}.pagename{margin-top:-11px}.nav:active,.nav:focus{height:auto}.nav div:before{background:#000;border-bottom:10px double;border-top:3px solid;content:'';float:right;height:4px;position:relative;right:3px;top:14px;width:20px}.nav a{padding:.5em 0;display:block;width:50%}}.table th,.table td{padding:.5em;text-align:left}.table tbody>:nth-child(2n-1){background:#ddd}.msg{padding:1.5em;background:#def;border-left:5px solid #59d}\n"
                "     .hero {\n"
                "       background: #eee;\n"
                "       padding: 20px;\n"
                "       border-radius: 10px;\n"
                "       margin-top: 1em;\n"
                "     }\n"
                "     .hero h1 {\n"
                "       margin-top: 0;\n"
                "       margin-bottom: 0.3em;\n"
                "     }\n"
                "     .c4 {\n"
                "       padding: 10px;\n"
                "       box-sizing: border-box;\n"
                "     }\n"
                "     .c4 h3 {\n"
                "       margin-top: 0;\n"
                "     }\n"
                "     \n"
                "     // Code from https://proto.io/freebies/onoff/\n"
                "     .c4 a {\n"
                "       margin-top: 10px;\n"
                "       display: inline-block;\n"
                "     }\n"
                "     \n"
                "     .onoffswitch {\n"
                "       position: relative; width: 90px;\n"
                "       -webkit-user-select:none; -moz-user-select:none; -ms-user-select: none;\n"
                "     }\n"
                "     .onoffswitch-checkbox {\n"
                "       position: absolute;\n"
                "       opacity: 0;\n"
                "       pointer-events: none;\n"
                "     }\n"
                "     .onoffswitch-label {\n"
                "       display: block; overflow: hidden; cursor: pointer;\n"
                "       border: 2px solid #999999; border-radius: 20px;\n"
                "     }\n"
                "     .onoffswitch-inner {\n"
                "       display: block; width: 200%; margin-left: -100%;\n"
                "       transition: margin 0.3s ease-in 0s;\n"
                "     }\n"
                "     .onoffswitch-inner:before, .onoffswitch-inner:after {\n"
                "       display: block; float: left; width: 50%; height: 30px; padding: 0; line-height: 30px;\n"
                "       font-size: 14px; color: white; font-family: Trebuchet, Arial, sans-serif; font-weight: bold;\n"
                "       box-sizing: border-box;\n"
                "     }\n"
                "     .onoffswitch-inner:before {\n"
                "       content: \"ON\";\n"
                "       padding-left: 10px;\n"
                "       background-color: #34A7C1; color: #FFFFFF;\n"
                "     }\n"
                "     .onoffswitch-inner:after {\n"
                "       content: \"OFF\";\n"
                "       padding-right: 10px;\n"
                "       background-color: #EEEEEE; color: #999999;\n"
                "       text-align: right;\n"
                "     }\n"
                "     .onoffswitch-switch {\n"
                "       display: block; width: 18px; margin: 6px;\n"
                "       background: #FFFFFF;\n"
                "       position: absolute; top: 0; bottom: 0;\n"
                "       right: 56px;\n"
                "       border: 2px solid #999999; border-radius: 20px;\n"
                "       transition: all 0.3s ease-in 0s; \n"
                "     }\n"
                "     .onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-inner {\n"
                "       margin-left: 0;\n"
                "     }\n"
                "     .onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-switch {\n"
                "       right: 0px; \n"
                "     }\n"
                "     \n"
                "     .grid-container {\n"
                "       display: grid;\n"
                "       grid-template-columns: 1fr 1fr;\n"
                "       grid-gap: 20px;\n"
                "     }\n"
                "     \n"
                "     .flex-container {\n"
                "       display: flex;\n"
                "       margin-top: 40px;\n"
                "     }\n"
                "     .flex-child {\n"
                "       flex: 1;\n"
                "       //border: 2px solid yellow;\n"
                "     }  \n"
                "     .flex-child:first-child {\n"
                "       margin-right: 20px;\n"
                "     } \n"
                "     \n"
                "     .component-label{\n"
                "       float: right;\n"
                "       font-weight: bold;\n"
                "       font-size: 25px;\n"
                "     }\n"
                "   </style>\n"
                " </head>\n"
                " <body>\n"
                "   <nav class=\"nav\" tabindex=\"-1\" onclick=\"this.focus()\">\n"
                "     <div class=\"container\">\n"
                "       <a class=\"pagename current\" href=\"#\">wwww.donskytech.com</a>\n"
                "     </div>\n"
                "   </nav>\n"
                "\n"
                "   <div class=\"container\">\n"
                "     <div class=\"hero\">\n"
                "       <h1>NodeMCU ESP8266 Web Server</h1>\n"
                "       <div class=\"flex-container\">\n"
                "         <div class=\"flex-child magenta\">\n"
                "         <span class=\"component-label\">LED</span>\n"
                "         </div>\n"
                "         <div class=\"flex-child green\">\n"
                "         <div class=\"grid-child green\">\n"
                "           <div style=\"display: inline\">\n"
                "             <div class=\"onoffswitch\">\n"
                "               <input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"ledSwitch\" tabindex=\"0\">\n"
                "               <label class=\"onoffswitch-label\" for=\"ledSwitch\">\n"
                "                 <span class=\"onoffswitch-inner\"></span>\n"
                "                 <span class=\"onoffswitch-switch\"></span>\n"
                "               </label>\n"
                "             </div>\n"
                "           </div>\n"
                "         </div>\n"
                "         </div>\n"
                "       </div>\n"
                "       <div class=\"flex-container\">\n"
                "         <div class=\"flex-child magenta\">\n"
                "         <span class=\"component-label\">Buzzer</span>\n"
                "         </div>\n"
                "         <div class=\"flex-child green\">\n"
                "         <div class=\"grid-child green\">\n"
                "           <div style=\"display: inline\">\n"
                "             <div class=\"onoffswitch\">\n"
                "               <input type=\"checkbox\" name=\"onoffswitch\" class=\"onoffswitch-checkbox\" id=\"buzzerSwitch\" tabindex=\"0\">\n"
                "               <label class=\"onoffswitch-label\" for=\"buzzerSwitch\">\n"
                "                 <span class=\"onoffswitch-inner\"></span>\n"
                "                 <span class=\"onoffswitch-switch\"></span>\n"
                "               </label>\n"
                "             </div>\n"
                "           </div>\n"
                "         </div>\n"
                "         </div>\n"
                "       </div>\n"
                "     </div>\n"
                "   </div>\n"
                "   <script>\n"
                "     document.getElementById('ledSwitch').onclick = function() {\n"
                "       // access properties using this keyword\n"
                "       var ledStatus;\n"
                "       if ( this.checked ) {\n"
                "         ledStatus = \"ON\";\n"
                "       } else {\n"
                "         ledStatus = \"OFF\";\n"
                "       }\n"
                "       var xhttp = new XMLHttpRequest();\n"
                "       xhttp.onreadystatechange = function() {\n"
                "         if (this.readyState == 4 && this.status == 200) {\n"
                "           console.log(\"Successfully received \");\n"
                "         }\n"
                "       };\n"
                "       xhttp.open(\"GET\", \"toggleLED?ledStatus=\"+ledStatus, true);\n"
                "       xhttp.send();\n"
                "     };\n"
                "     document.getElementById('buzzerSwitch').onclick = function() {\n"
                "       // access properties using this keyword\n"
                "       var buzzerStatus;\n"
                "       if ( this.checked ) {\n"
                "         buzzerStatus = \"ON\";\n"
                "       } else {\n"
                "         buzzerStatus = \"OFF\";\n"
                "       }\n"
                "       var xhttp = new XMLHttpRequest();\n"
                "       xhttp.onreadystatechange = function() {\n"
                "         if (this.readyState == 4 && this.status == 200) {\n"
                "           \n"
                "         }\n"
                "       };\n"
                "       xhttp.open(\"GET\", \"toggleBuzzer?buzzerStatus=\"+buzzerStatus, true);\n"
                "       xhttp.send();\n"
                "     };\n"
                "   </script>\n"
                " </body>\n"
                "</html>\n";


  return html;
}
