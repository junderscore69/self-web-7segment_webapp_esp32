#include <WiFi.h>
#include <WebServer.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver();

const int NUM_DIGITS = 4;
const int servoChannels[NUM_DIGITS] = {3, 2, 1, 0};  // Left to right: HHMM

const int digitPositions[10] = {
  150,  // 0  ← replace these with your tuned PWM values
  194,  // 1
  238,  // 2
  282,  // 3
  330,  // 4
  370,  // 5
  414,  // 6
  458,  // 7
  500,  // 8
  540   // 9
};

void setServoDigit(int index, int digit) {
  if (index < 0 || index >= NUM_DIGITS) return;
  if (digit < 0 || digit > 9) return;

  int channel = servoChannels[index];
  int pwmVal = digitPositions[digit];

  pca.setPWM(channel, 0, pwmVal);
  delay(600); // settle
  pca.setPWM(channel, 0, 0); // relax
}

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char CLOCK_BASE_SVG[] PROGMEM = R"rawliteral(

<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!-- Created with Inkscape (http://www.inkscape.org/) -->

<svg
   width="289.06244mm"
   height="79mm"
   viewBox="0 0 289.06244 79"
   version="1.1"
   id="svg1"
   inkscape:version="1.4.2 (f4327f4, 2025-05-13)"
   sodipodi:docname="Clock baseplate.svg"
   xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape"
   xmlns:sodipodi="http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd"
   xmlns:xlink="http://www.w3.org/1999/xlink"
   xmlns="http://www.w3.org/2000/svg"
   xmlns:svg="http://www.w3.org/2000/svg">
  <sodipodi:namedview
     id="namedview1"
     pagecolor="#ffffff"
     bordercolor="#000000"
     borderopacity="0.25"
     inkscape:showpageshadow="2"
     inkscape:pageopacity="0.0"
     inkscape:pagecheckerboard="0"
     inkscape:deskcolor="#d1d1d1"
     inkscape:document-units="mm"
     showgrid="true"
     inkscape:zoom="0.37449231"
     inkscape:cx="634.19193"
     inkscape:cy="148.20064"
     inkscape:window-width="2560"
     inkscape:window-height="1369"
     inkscape:window-x="2552"
     inkscape:window-y="-8"
     inkscape:window-maximized="1"
     inkscape:current-layer="Layer 1">
    <inkscape:grid
       id="grid1"
       units="mm"
       originx="0"
       originy="72.000001"
       spacingx="0.99999998"
       spacingy="1"
       empcolor="#0099e5"
       empopacity="0.30196078"
       color="#0099e5"
       opacity="0.14901961"
       empspacing="5"
       enabled="true"
       visible="true" />
  </sodipodi:namedview>
  <defs
     id="defs1">
    <linearGradient
       id="linearGradient4"
       inkscape:collect="always">
      <stop
         style="stop-color:#1a1a1a;stop-opacity:1;"
         offset="0"
         id="stop4" />
      <stop
         style="stop-color:#000000;stop-opacity:1;"
         offset="1"
         id="stop5" />
    </linearGradient>
    <inkscape:path-effect
       effect="offset"
       id="path-effect2"
       is_visible="true"
       lpeversion="1.3"
       linejoin_type="miter"
       unit="mm"
       offset="-1"
       miter_limit="4"
       attempt_force_join="false"
       update_on_knot_move="true" />
    <inkscape:path-effect
       effect="offset"
       id="path-effect2-1"
       is_visible="true"
       lpeversion="1.3"
       linejoin_type="miter"
       unit="mm"
       offset="-1"
       miter_limit="4"
       attempt_force_join="false"
       update_on_knot_move="true" />
    <linearGradient
       inkscape:collect="always"
       xlink:href="#linearGradient4"
       id="linearGradient5"
       x1="144.49998"
       y1="-13.499994"
       x2="144.49998"
       y2="-1.499998"
       gradientUnits="userSpaceOnUse" />
  </defs>
  <g
     inkscape:label="Layer 1"
     inkscape:groupmode="layer"
     id="Layer 1"
     transform="translate(0,72)">
    <rect
       style="fill:#000000;fill-opacity:1;stroke-width:0"
       id="Colon Base"
       width="25.00001"
       height="3.9999998"
       x="132"
       y="0"
       inkscape:label="Colon Base" />
    <rect
       style="fill:#1a1a1a;stroke-width:0"
       id="Colon Support"
       width="12"
       height="48"
       x="138.5"
       y="-63"
       ry="0"
       rx="0"
       inkscape:label="Colon Support" />
    <circle
       style="fill:#1a1a1a;stroke-width:0"
       id="Colon 1 Black"
       cx="144.53122"
       cy="-27"
       r="9"
       inkscape:label="Colon 1 Black" />
    <path
       style="fill:#ffffff;stroke-width:0"
       id="Colon 1 White"
       inkscape:path-effect="#path-effect2"
       sodipodi:type="arc"
       sodipodi:cx="136.5388"
       sodipodi:cy="59"
       sodipodi:rx="9"
       sodipodi:ry="9"
       d="m 136.53906,51.009766 c -4.42472,0 -7.99023,3.565516 -7.99023,7.990234 0,4.424718 3.56551,7.990234 7.99023,7.990234 4.42472,0 7.99024,-3.565516 7.99024,-7.990234 0,-4.424718 -3.56552,-7.990234 -7.99024,-7.990234 z"
       transform="translate(7.9924212,-86)"
       inkscape:label="Colon 1 White" />
    <circle
       style="fill:#1a1a1a;stroke-width:0"
       id="Colon 2 Black"
       cx="144.53122"
       cy="-63"
       r="9"
       inkscape:label="Colon 2 Black" />
    <path
       style="fill:#ffffff;stroke-width:0"
       id="Colon 2 White"
       inkscape:path-effect="#path-effect2-1"
       sodipodi:type="arc"
       sodipodi:cx="136.5388"
       sodipodi:cy="59"
       sodipodi:rx="9"
       sodipodi:ry="9"
       d="m 136.53906,51.009766 c -4.42472,0 -7.99023,3.565516 -7.99023,7.990234 0,4.424718 3.56551,7.990234 7.99023,7.990234 4.42472,0 7.99024,-3.565516 7.99024,-7.990234 0,-4.424718 -3.56552,-7.990234 -7.99024,-7.990234 z"
       transform="translate(7.9924212,-122)"
       inkscape:label="Colon 2 White" />
    <rect
       style="fill:url(#linearGradient5);stroke-width:0"
       id="rect4"
       width="12"
       height="15"
       x="138.49998"
       y="-15" />
  </g>
  <g
     inkscape:groupmode="layer"
     id="Layer 2"
     inkscape:label="Layer 2"
     transform="translate(0,72)">
    <rect
       style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
       id="Baseplate1"
       width="133"
       height="7"
       x="0"
       y="0"
       rx="0.99999696"
       ry="0.99999696"
       inkscape:label="Baseplate1" />
    <rect
       style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
       id="Baseplate2"
       width="133"
       height="7"
       x="156.06244"
       y="0"
       rx="1"
       ry="1"
       inkscape:label="Baseplate2" />
  </g>
</svg>

)rawliteral";

const char DIGIT_SVG[] PROGMEM = R"rawliteral(

<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<svg
   width="60mm"
   height="117.5mm"
   viewBox="0 0 60 117.5"
   version="1.1"
   id="svg1"
   sodipodi:docname="7segdigit.svg"
   inkscape:version="1.4.2 (ebf0e940d0, 2025-05-08)"
   xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape"
   xmlns:sodipodi="http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd"
   xmlns:xlink="http://www.w3.org/1999/xlink"
   xmlns="http://www.w3.org/2000/svg"
   xmlns:svg="http://www.w3.org/2000/svg">
  <sodipodi:namedview
     id="namedview1"
     pagecolor="#ffffff"
     bordercolor="#000000"
     borderopacity="0.25"
     inkscape:showpageshadow="2"
     inkscape:pageopacity="0.0"
     inkscape:pagecheckerboard="0"
     inkscape:deskcolor="#d1d1d1"
     inkscape:document-units="mm"
     inkscape:zoom="2"
     inkscape:cx="-26.5"
     inkscape:cy="212.5"
     inkscape:window-width="2560"
     inkscape:window-height="1403"
     inkscape:window-x="0"
     inkscape:window-y="0"
     inkscape:window-maximized="1"
     inkscape:current-layer="Segment E"
     showgrid="true">
    <inkscape:grid
       id="grid1"
       units="mm"
       originx="9.3998883e-16"
       originy="-1.363637e-08"
       spacingx="0.99999998"
       spacingy="1"
       empcolor="#0099e5"
       empopacity="0.30196078"
       color="#0099e5"
       opacity="0.14901961"
       empspacing="5"
       enabled="true"
       visible="true" />
  </sodipodi:namedview>
  <defs
     id="defs1">
    <linearGradient
       id="linearGradient50"
       inkscape:collect="always">
      <stop
         style="stop-color:#0f0f0f;stop-opacity:1;"
         offset="0"
         id="stop51" />
      <stop
         style="stop-color:#0d0d0d;stop-opacity:1;"
         offset="0.52137935"
         id="stop54" />
      <stop
         style="stop-color:#0d0d0d;stop-opacity:1;"
         offset="0.7489655"
         id="stop53" />
      <stop
         style="stop-color:#0f0f0f;stop-opacity:1;"
         offset="1"
         id="stop52" />
    </linearGradient>
    <inkscape:path-effect
       effect="fillet_chamfer"
       id="path-effect4"
       is_visible="true"
       lpeversion="1"
       nodesatellites_param="F,0,0,1,0,4.4999999,0,1 @ F,0,0,1,0,4.4999999,0,1 @ F,0,0,1,0,4.4999999,0,1 @ F,0,0,1,0,4.4999999,0,1"
       radius="4.5"
       unit="mm"
       method="auto"
       mode="F"
       chamfer_steps="1"
       flexible="false"
       use_knot_distance="true"
       apply_no_radius="true"
       apply_with_radius="true"
       only_selected="false"
       hide_knots="false" />
    <inkscape:path-effect
       effect="fillet_chamfer"
       id="path-effect3"
       is_visible="true"
       lpeversion="1"
       nodesatellites_param="F,0,0,1,0,1.5,0,1 @ F,0,0,1,0,1.5,0,1 @ F,0,0,1,0,1.5,0,1 @ F,0,0,1,0,1.5,0,1"
       radius="1.5"
       unit="mm"
       method="auto"
       mode="F"
       chamfer_steps="1"
       flexible="false"
       use_knot_distance="true"
       apply_no_radius="true"
       apply_with_radius="true"
       only_selected="false"
       hide_knots="false" />
    <inkscape:path-effect
       effect="offset"
       id="path-effect2"
       is_visible="true"
       lpeversion="1.3"
       linejoin_type="miter"
       unit="mm"
       offset="-4.5"
       miter_limit="4"
       attempt_force_join="false"
       update_on_knot_move="true" />
    <inkscape:path-effect
       effect="offset"
       id="path-effect1"
       is_visible="true"
       lpeversion="1.3"
       linejoin_type="miter"
       unit="mm"
       offset="-1"
       miter_limit="4"
       attempt_force_join="false"
       update_on_knot_move="true" />
    <inkscape:path-effect
       effect="offset"
       id="path-effect1-4"
       is_visible="true"
       lpeversion="1.3"
       linejoin_type="miter"
       unit="mm"
       offset="-0.928712"
       miter_limit="4"
       attempt_force_join="false"
       update_on_knot_move="true" />
    <linearGradient
       inkscape:collect="always"
       xlink:href="#linearGradient50"
       id="linearGradient52"
       x1="-105.73699"
       y1="-38.566408"
       x2="-104.7219"
       y2="-38.566408"
       gradientUnits="userSpaceOnUse" />
    <linearGradient
       inkscape:collect="always"
       xlink:href="#linearGradient50"
       id="linearGradient54"
       gradientUnits="userSpaceOnUse"
       x1="-105.73699"
       y1="-38.566408"
       x2="-104.7219"
       y2="-38.566408"
       gradientTransform="translate(221.25598,77.132818)" />
    <linearGradient
       inkscape:collect="always"
       xlink:href="#linearGradient50"
       id="linearGradient1"
       gradientUnits="userSpaceOnUse"
       x1="-105.73699"
       y1="-38.566408"
       x2="-104.7219"
       y2="-38.566408" />
    <linearGradient
       inkscape:collect="always"
       xlink:href="#linearGradient50"
       id="linearGradient2"
       gradientUnits="userSpaceOnUse"
       gradientTransform="translate(220.24089,77.132816)"
       x1="-105.73699"
       y1="-38.566408"
       x2="-104.7219"
       y2="-38.566408" />
    <linearGradient
       inkscape:collect="always"
       xlink:href="#linearGradient50"
       id="linearGradient21"
       gradientUnits="userSpaceOnUse"
       x1="-105.73699"
       y1="-38.566408"
       x2="-104.7219"
       y2="-38.566408" />
    <linearGradient
       inkscape:collect="always"
       xlink:href="#linearGradient50"
       id="linearGradient22"
       gradientUnits="userSpaceOnUse"
       gradientTransform="translate(220.24089,77.132816)"
       x1="-105.73699"
       y1="-38.566408"
       x2="-104.7219"
       y2="-38.566408" />
    <linearGradient
       inkscape:collect="always"
       xlink:href="#linearGradient50"
       id="linearGradient23"
       gradientUnits="userSpaceOnUse"
       x1="-105.73699"
       y1="-38.566408"
       x2="-104.7219"
       y2="-38.566408" />
    <linearGradient
       inkscape:collect="always"
       xlink:href="#linearGradient50"
       id="linearGradient24"
       gradientUnits="userSpaceOnUse"
       gradientTransform="translate(221.25598,77.132818)"
       x1="-105.73699"
       y1="-38.566408"
       x2="-104.7219"
       y2="-38.566408" />
  </defs>
  <g
     inkscape:groupmode="layer"
     id="Frame"
     inkscape:label="Frame"
     style="display:inline">
    <path
       id="knob"
       style="display:inline;stroke-width:0"
       d="M 39.473229,1.363637e-8 H 20.527247 C 19.681284,1.363637e-8 19.000238,0.48240823 19.000238,1.081632 V 15.918369 C 19.000238,16.517593 19.681284,17 20.527247,17 h 18.945982 c 0.845963,0 1.527009,-0.482407 1.527009,-1.081631 V 1.081632 C 41.000238,0.48240823 40.319192,1.3636369e-8 39.473229,1.363637e-8 Z" />
    <path
       id="spring_support"
       style="display:inline;fill:#070707;fill-opacity:1;stroke-width:0"
       d="m 42.945234,11 h -25.89 v 6 h 25.89 z" />
    <path
       id="spring"
       style="display:inline;stroke-width:0"
       d="M 48.508443,10 H 11.493021 v 3.344623 h 37.015422 z" />
    <path
       id="frame"
       d="M 4.4999999,17 H 55.5 A 4.4999999,4.4999999 45 0 1 60,21.5 V 113 a 4.4999999,4.4999999 135 0 1 -4.5,4.5 H 4.4999999 A 4.4999999,4.4999999 45 0 1 0,113 V 21.5 A 4.4999999,4.4999999 135 0 1 4.4999999,17 Z"
       style="fill:#020202;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none"
       inkscape:label="frame" />
    <path
       id="frame interior"
       d="m 4.2350265,23.026301 v 88.480469 a 1.5,1.5 0 0 0 1.5,1.5 H 53.715495 a 1.5,1.5 0 0 0 1.5,-1.5 V 23.026301 a 1.5,1.5 0 0 0 -1.5,-1.5 H 5.7350265 a 1.5,1.5 0 0 0 -1.5,1.5 z"
       style="display:inline;fill:#121212;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none"
       inkscape:label="frame interior" />
    <path
       id="knob indent 1"
       style="fill:#0c0c0c;stroke-width:0"
       inkscape:label="knob indent 1"
       d="m 27,0.99999976 c 0.554,0 1,0.44600004 1,1.00000004 v 7 c 0,0.554 -0.446,1 -1,1 -0.554,0 -1,-0.446 -1,-1 v -7 c 0,-0.554 0.446,-1.00000004 1,-1.00000004 z" />
    <path
       id="knob indent 2"
       style="display:inline;fill:#0a0a0a;stroke-width:0"
       inkscape:label="knob indent 2"
       d="m 23.999762,0.99927992 c 0.554,0 1,0.44599998 1,0.99999998 v 7 c 0,0.554 -0.446,1 -1,1 -0.554,0 -1,-0.446 -1,-1 v -7 c 0,-0.554 0.446,-0.99999998 1,-0.99999998 z" />
    <path
       id="knob indent 3"
       style="display:inline;fill:#0a0a0a;stroke-width:0"
       inkscape:label="knob indent 3"
       d="m 20.999523,0.99999988 c 0.554,0 1,0.44600002 1,1.00000002 v 7 c 0,0.554 -0.446,1 -1,1 -0.554,0 -1,-0.446 -1,-1 v -7 c 0,-0.554 0.446,-1.00000002 1,-1.00000002 z" />
    <path
       id="knob indent 4"
       style="display:inline;fill:#0f0f0f;stroke-width:0"
       inkscape:label="knob indent 4"
       d="m 30.000238,0.99927992 c 0.554,0 1,0.44599998 1,0.99999998 v 7 c 0,0.554 -0.446,1 -1,1 -0.554,0 -1,-0.446 -1,-1 v -7 c 0,-0.554 0.446,-0.99999998 1,-0.99999998 z" />
    <path
       id="knob indent 5"
       style="display:inline;fill:#090909;stroke-width:0"
       inkscape:label="knob indent 5"
       d="m 33,0.9999997 c 0.554,0 1,0.446 1,1 v 7 c 0,0.554 -0.446,1 -1,1 -0.554,0 -1,-0.446 -1,-1 v -7 c 0,-0.554 0.446,-1 1,-1 z" />
    <path
       id="knob indent 6"
       style="display:inline;fill:#080808;stroke-width:0"
       inkscape:label="knob indent 6"
       d="m 35.999763,0.99927992 c 0.554,0 1,0.44599998 1,0.99999998 v 7 c 0,0.554 -0.446,1 -1,1 -0.554,0 -1,-0.446 -1,-1 v -7 c 0,-0.554 0.446,-0.99999998 1,-0.99999998 z" />
    <path
       id="knob indent 7"
       style="display:inline;fill:#080808;stroke-width:0"
       inkscape:label="knob indent 7"
       d="m 38.999527,0.99927992 c 0.554,0 1,0.44599998 1,0.99999998 v 7 c 0,0.554 -0.446,1 -1,1 -0.554,0 -1,-0.446 -1,-1 v -7 c 0,-0.554 0.446,-0.99999998 1,-0.99999998 z" />
  </g>
  <g
     inkscape:groupmode="layer"
     id="FrameSegment_Support"
     inkscape:label="Gears and Supports"
     style="display:inline">
    <g
       id="Frame_Hinge_Supports"
       style="display:inline">
      <path
         d="m 41.000598,103.99985 v 9.50123 h 3.999756 v -9.50123 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports01" />
      <path
         d="m 13.629659,106.00025 v 5.50095 h 1.370459 v -5.50095 z"
         style="fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports02" />
      <path
         d="m 45.000871,106.00025 v 5.50095 h 1.370459 v -5.50095 z"
         style="fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports03" />
      <path
         d="m 15.000118,103.99985 v 9.50123 h 3.999756 v -9.50123 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports04" />
      <path
         d="m 3.2494141,100.74992 v 4.00028 h 1.9998779 5.501473 1.999878 v -4.00028 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports05" />
      <path
         d="m 5.249292,73.378984 v 1.370459 h 5.501473 v -1.370459 z"
         style="fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports06" />
      <path
         d="m 5.249292,104.7502 v 1.37097 h 5.501473 v -1.37097 z"
         style="fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports07" />
      <path
         d="m 3.2494141,74.749443 v 4.000272 h 9.5012289 v -4.000272 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports08" />
      <path
         d="m 47.498393,55.750085 v 4.000273 h 1.999878 5.500956 2.000395 v -4.000273 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports09" />
      <path
         d="m 49.498271,28.379146 v 1.370459 h 5.500956 v -1.370459 z"
         style="display:inline;fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports10" />
      <path
         d="m 49.498271,59.750358 v 1.370976 h 5.500956 v -1.370976 z"
         style="display:inline;fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports11" />
      <path
         d="m 47.498393,29.749605 v 4.000273 h 9.501229 v -4.000273 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports12" />
      <path
         d="m 3.5010783,55.750085 v 4.000273 h 1.9998779 5.5009558 2.000395 v -4.000273 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports13" />
      <path
         d="m 5.5009562,28.379146 v 1.370459 h 5.5009558 v -1.370459 z"
         style="display:inline;fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports14" />
      <path
         d="m 5.5009562,59.750358 v 1.370976 h 5.5009558 v -1.370976 z"
         style="display:inline;fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports15" />
      <path
         d="m 3.5010783,29.749605 v 4.000273 h 9.5012287 v -4.000273 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports16" />
      <path
         d="m 46.998165,100.74992 v 4.00028 h 2.000395 5.500956 1.999878 v -4.00028 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports17" />
      <path
         d="m 48.99856,73.378984 v 1.370459 h 5.500956 v -1.370459 z"
         style="display:inline;fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports18" />
      <path
         d="m 48.99856,104.7502 v 1.37097 h 5.500956 v -1.37097 z"
         style="display:inline;fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports19" />
      <path
         d="m 46.998165,74.749443 v 4.000272 h 9.501229 v -4.000272 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports20" />
      <path
         d="m 41.000598,20.001363 v 9.501229 h 3.999756 v -9.501229 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports21" />
      <path
         d="m 13.629659,22.001241 v 5.501473 h 1.370459 v -5.501473 z"
         style="display:inline;fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports22" />
      <path
         d="m 45.000871,22.001241 v 5.501473 h 1.370459 v -5.501473 z"
         style="display:inline;fill:#0d0d0d;stroke-width:0"
         id="Frame_Hinge_Supports23" />
      <path
         d="m 15.000118,20.001363 v 9.501229 h 3.999756 v -9.501229 z"
         style="display:inline;fill:#0f0f0f;stroke-width:0"
         id="Frame_Hinge_Supports24" />
    </g>
    <g
       id="FrameSegmentGGear"
       transform="matrix(1,0,0,-1,-5e-7,169.74946)">
      <rect
         style="fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentGGear01"
         width="4.9999981"
         height="6.2479129"
         x="28"
         y="97.752083" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentGGear02"
         width="1.3708115"
         height="6.2479157"
         x="33"
         y="97.752083"
         ry="0"
         rx="0" />
      <rect
         style="fill:#141414;fill-opacity:1;stroke-width:0"
         id="FrameSegmentGGear03"
         width="6.0000014"
         height="0.75045675"
         x="27"
         y="105" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentGGear04"
         width="1"
         height="7.2479157"
         x="27"
         y="97.752083" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentGGear05"
         width="5.0000005"
         height="0.99999863"
         x="27.999998"
         y="104" />
    </g>
    <g
       id="SegmentFGear"
       transform="matrix(0,-1,-1,0,132.7219,79.566405)"
       style="display:inline">
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentFGear01"
         width="1.3708115"
         height="4.9999962"
         x="40.620575"
         y="99.721901"
         ry="0"
         rx="0" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentFGear2"
         width="0.77112103"
         height="5"
         x="35.740845"
         y="-104.7219"
         transform="scale(1,-1)" />
      <rect
         style="display:inline;fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentFGear03"
         width="4.1088805"
         height="4.9999981"
         x="36.511967"
         y="99.721901" />
      <rect
         style="fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentFGear04"
         width="3.9999971"
         height="10"
         x="-120.53407"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentFGear05"
         width="9.7819872"
         height="4.1088839"
         x="-115.51898"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:url(#linearGradient23);fill-opacity:1;stroke-width:0"
         id="FrameSegmentFGear6"
         width="1.0150906"
         height="4.1088839"
         x="-105.73699"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:url(#linearGradient24);fill-opacity:1;stroke-width:0"
         id="FrameSegmentFGear07"
         width="1.0150906"
         height="4.1088839"
         x="115.51898"
         y="36.511967"
         transform="matrix(0,1,1,0,0,0)" />
      <rect
         style="display:inline;fill:#141414;fill-opacity:1;stroke-width:0"
         id="FrameSegmentFGear08"
         width="1.0004793"
         height="10"
         x="-121.53455"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
    </g>
    <g
       id="FrameSegmentEGear"
       transform="matrix(0,-1,-1,0,132.7219,121.0625)"
       style="display:inline">
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentEGear01"
         width="1.3708115"
         height="4.9999962"
         x="40.620575"
         y="99.721901"
         ry="0"
         rx="0" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentEGear02"
         width="0.77112103"
         height="5"
         x="35.740845"
         y="-104.7219"
         transform="scale(1,-1)" />
      <rect
         style="display:inline;fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentEGear03"
         width="4.1088805"
         height="4.9999981"
         x="36.511967"
         y="99.721901" />
      <rect
         style="fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentEGear04"
         width="3.9999971"
         height="10"
         x="-120.53407"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentEGear05"
         width="9.7819872"
         height="4.1088839"
         x="-115.51898"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:url(#linearGradient52);fill-opacity:1;stroke-width:0"
         id="FrameSegmentEGear06"
         width="1.0150906"
         height="4.1088839"
         x="-105.73699"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:url(#linearGradient54);fill-opacity:1;stroke-width:0"
         id="FrameSegmentEGear07"
         width="1.0150906"
         height="4.1088839"
         x="115.51898"
         y="36.511967"
         transform="matrix(0,1,1,0,0,0)" />
      <rect
         style="display:inline;fill:#141414;fill-opacity:1;stroke-width:0"
         id="FrameSegmentEGear08"
         width="1.0004793"
         height="10"
         x="-121.53455"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
    </g>
    <g
       id="FrameSegmentDGear"
       style="display:inline">
      <rect
         style="fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentDGear01"
         width="4.9999981"
         height="6.2479129"
         x="28"
         y="97.752083" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentDGear02"
         width="1.3708115"
         height="6.2479157"
         x="33"
         y="97.752083"
         ry="0"
         rx="0" />
      <rect
         style="fill:#141414;fill-opacity:1;stroke-width:0"
         id="FrameSegmentDGear03"
         width="6.0000014"
         height="0.75045675"
         x="27"
         y="105" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentDGear04"
         width="1"
         height="7.2479157"
         x="27"
         y="97.752083" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentDGear05"
         width="5.0000005"
         height="0.99999863"
         x="27.999998"
         y="104" />
    </g>
    <g
       id="FrameSegmentCGear"
       transform="matrix(0,1,1,0,-71.721893,52.694017)"
       style="display:inline">
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentCGear01"
         width="1.3708115"
         height="4.9999962"
         x="40.620575"
         y="99.721901"
         ry="0"
         rx="0" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentCGear02"
         width="0.77112103"
         height="5"
         x="35.740845"
         y="-104.7219"
         transform="scale(1,-1)" />
      <rect
         style="display:inline;fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentCGear03"
         width="4.1088805"
         height="4.9999981"
         x="36.511967"
         y="99.721901" />
      <rect
         style="fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentCGear04"
         width="3.9999971"
         height="10"
         x="-119.51898"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentCGear05"
         width="9.7819872"
         height="4.1088839"
         x="-115.51898"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:url(#linearGradient1);fill-opacity:1;stroke-width:0"
         id="FrameSegmentCGear06"
         width="1.0150906"
         height="4.1088839"
         x="-105.73699"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:url(#linearGradient2);fill-opacity:1;stroke-width:0"
         id="FrameSegmentCGear07"
         width="1.0150906"
         height="4.1088839"
         x="114.50389"
         y="36.511967"
         transform="matrix(0,1,1,0,0,0)" />
      <rect
         style="display:inline;fill:#141414;fill-opacity:1;stroke-width:0"
         id="FrameSegmentCGear08"
         width="1.0004793"
         height="10"
         x="-120.51946"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
    </g>
    <g
       id="FrameSegmentBGear"
       transform="matrix(0,1,1,0,-71.721893,11.197924)"
       style="display:inline">
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentBGear01"
         width="1.3708115"
         height="4.9999962"
         x="40.620575"
         y="99.721901"
         ry="0"
         rx="0" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentBGear02"
         width="0.77112103"
         height="5"
         x="35.740845"
         y="-104.7219"
         transform="scale(1,-1)" />
      <rect
         style="display:inline;fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentBGear03"
         width="4.1088805"
         height="4.9999981"
         x="36.511967"
         y="99.721901" />
      <rect
         style="fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentBGear04"
         width="3.9999971"
         height="10"
         x="-119.51898"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentBGear05"
         width="9.7819872"
         height="4.1088839"
         x="-115.51898"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:url(#linearGradient21);fill-opacity:1;stroke-width:0"
         id="FrameSegmentBGear06"
         width="1.0150906"
         height="4.1088839"
         x="-105.73699"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
      <rect
         style="display:inline;fill:url(#linearGradient22);fill-opacity:1;stroke-width:0"
         id="FrameSegmentBGear07"
         width="1.0150906"
         height="4.1088839"
         x="114.50389"
         y="36.511967"
         transform="matrix(0,1,1,0,0,0)" />
      <rect
         style="display:inline;fill:#141414;fill-opacity:1;stroke-width:0"
         id="FrameSegmentBGear08"
         width="1.0004793"
         height="10"
         x="-120.51946"
         y="-40.62085"
         transform="matrix(0,-1,-1,0,0,0)" />
    </g>
    <g
       id="FrameSegmentAGear"
       transform="rotate(180,30.342703,67)"
       style="display:inline">
      <rect
         style="fill:#0f0f0f;fill-opacity:1;stroke-width:0"
         id="FrameSegmentAGear01"
         width="4.9999981"
         height="6.2479129"
         x="28"
         y="97.752083" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentAGear02"
         width="1.3708115"
         height="6.2479157"
         x="33"
         y="97.752083"
         ry="0"
         rx="0" />
      <rect
         style="fill:#141414;fill-opacity:1;stroke-width:0"
         id="FrameSegmentAGear03"
         width="6.0000014"
         height="0.75045675"
         x="27"
         y="105" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentAGear04"
         width="1"
         height="7.2479157"
         x="27"
         y="97.752083" />
      <rect
         style="fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         id="FrameSegmentAGear05"
         width="5.0000005"
         height="0.99999863"
         x="27.999998"
         y="104" />
    </g>
  </g>
  <g
     inkscape:groupmode="layer"
     id="Segment G"
     inkscape:label="Segment G"
     style="display:inline">
    <g
       inkscape:groupmode="layer"
       id="Segment G Closed"
       inkscape:label="Segment G Closed"
       style="display:inline">
      <path
         id="segment g0"
         style="display:inline;fill:#000000;stroke-width:0"
         d="m 17.5,61.75 h 25 v 11 h -25 z"
         inkscape:label="segment g0" />
      <path
         id="segment g1"
         style="fill:#f2f2f2;stroke-width:0"
         d="m 18.5,62.75 v 8.980468 H 41.480468 V 62.75 Z"
         inkscape:label="segment g1" />
    </g>
    <g
       inkscape:groupmode="layer"
       id="Segment G Open"
       inkscape:label="Segment G Open">
      <path
         id="segment g2"
         style="fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment g2"
         d="m 17.5,52.75 h 25 v 4 h -25 z" />
      <path
         id="segment g3"
         style="fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment g3"
         d="m 22,56.749458 h 15.999999 v 8 H 22 Z" />
      <path
         id="segment g6"
         style="fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment g6"
         d="m 38,56.749458 h 3.000001 v 8 H 38 Z" />
      <path
         id="segment g5"
         style="fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment g5"
         d="m 19,56.749458 h 3 v 8 h -3 z" />
      <path
         id="segment g7"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment g7"
         d="m 22,64 h 16 v 0.749458 H 22 Z" />
      <path
         id="segment g8"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment g8"
         d="m 21.990234,62.000542 h 16 v 0.999457 h -16 z" />
      <path
         id="segment g9"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment g9"
         d="m 22,60.001083 h 16 v 0.999458 H 22 Z" />
      <path
         id="segment g10"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment g10"
         d="m 22,58.001625 h 16 v 0.999458 H 22 Z" />
      <path
         id="segment g11"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment g11"
         d="M 22,56.75 H 38 V 57 H 22 Z" />
    </g>
  </g>
  <g
     inkscape:groupmode="layer"
     id="Segment F"
     inkscape:label="Segment F"
     style="display:inline">
    <g
       inkscape:groupmode="layer"
       id="Segment F Closed"
       inkscape:label="Segment F Closed"
       style="display:inline">
      <path
         id="segment f0"
         style="display:inline;fill:#000000;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none;stroke-opacity:1"
         d="M 16,33.499795 V 67.000008 H 5 V 22.5 Z"
         inkscape:label="segment f0" />
      <path
         id="segment f1"
         style="fill:#f2f2f2;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none;stroke-opacity:1"
         d="m 6,24.929687 v 41.050781 h 8.980468 V 33.910156 Z"
         inkscape:label="segment f1" />
    </g>
    <g
       inkscape:groupmode="layer"
       id="Segment F Open"
       inkscape:label="Segment F Open">
      <path
         id="segment f2"
         style="display:inline;fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         d="M 0,22.5 H 3.999999 V 66.999998 H 0 Z"
         inkscape:label="segment f2" />
      <path
         id="segment f3"
         style="fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment f3"
         d="m 4.000065,52.749997 3.48e-4,-16 8,1.73e-4 -3.48e-4,15.999999 z" />
      <path
         id="segment f6"
         style="fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment f6"
         d="m 4.000413,36.749997 6.5e-5,-3.000001 8,1.73e-4 -6.5e-5,3.000001 z" />
      <path
         id="segment f5"
         style="fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment f5"
         d="m 4,55.749997 6.5e-5,-3 8,1.72e-4 -6.5e-5,3 z" />
      <path
         id="segment f7"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment f7"
         d="m 11.250607,52.750154 3.48e-4,-16.000001 0.749458,1.6e-5 -3.48e-4,16 z" />
      <path
         id="segment f8"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment f8"
         d="m 9.251149,52.759877 3.48e-4,-16.000001 0.999457,2.1e-5 -3.48e-4,16.000001 z" />
      <path
         id="segment f9"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment f9"
         d="m 7.25169,52.750067 3.48e-4,-16.000001 0.999458,2.2e-5 -3.48e-4,16.000001 z" />
      <path
         id="segment f10"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment f10"
         d="m 5.252232,52.750024 3.48e-4,-16.000001 0.999458,2.2e-5 -3.48e-4,16 z" />
      <path
         id="segment f11"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment f11"
         d="m 4.000607,52.749997 3.48e-4,-16.000001 0.25,5e-6 -3.48e-4,16.000001 z" />
    </g>
  </g>
  <g
     inkscape:groupmode="layer"
     id="Segment E"
     inkscape:label="Segment E"
     style="display:inline">
    <g
       inkscape:groupmode="layer"
       id="Segment E Closed"
       inkscape:label="Segment E Closed"
       style="display:inline">
      <path
         id="segment e0"
         style="display:inline;fill:#000000;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none;stroke-opacity:1"
         d="M 16,101.00022 V 67.499999 H 5 v 44.500011 z"
         inkscape:label="segment e0" />
      <path
         id="segment e1"
         style="display:inline;fill:#f2f2f2;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none;stroke-opacity:1"
         d="m 6,68.5 v 41.05078 l 8.980468,-8.98047 V 68.5 Z"
         inkscape:label="segment e1" />
    </g>
    <g
       inkscape:groupmode="layer"
       id="Segment E Open"
       inkscape:label="Segment E Open">
      <path
         id="segment e2"
         style="display:inline;fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         d="M 0,67.5 H 3.9999989 V 112 H 0 Z"
         inkscape:label="segment e2" />
      <path
         id="segment e3"
         style="fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment e3"
         d="m 4.000065,97.749963 3.48e-4,-16 8,1.73e-4 -3.48e-4,15.999999 z" />
      <path
         id="segment e6"
         style="fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment e6"
         d="m 4.000413,81.749963 6.5e-5,-3.000001 8,1.73e-4 -6.5e-5,3.000001 z" />
      <path
         id="segment e5"
         style="fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment e5"
         d="m 4,100.74996 6.5e-5,-2.999997 8,1.72e-4 L 12,100.75013 Z" />
      <path
         id="segment e7"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment e7"
         d="m 11.250607,97.75012 3.48e-4,-16.000001 0.749458,1.6e-5 -3.48e-4,16 z" />
      <path
         id="segment e8"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment e8"
         d="m 9.251149,97.759843 3.48e-4,-16.000001 0.999457,2.1e-5 -3.48e-4,16.000001 z" />
      <path
         id="segment e9"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment e9"
         d="m 7.25169,97.750033 3.48e-4,-16.000001 0.999458,2.2e-5 -3.48e-4,16.000001 z" />
      <path
         id="segment e10"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment e10"
         d="m 5.252232,97.74999 3.48e-4,-16.000001 0.999458,2.2e-5 -3.48e-4,16 z" />
      <path
         id="segment e11"
         style="fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment e11"
         d="m 4.000607,97.749963 3.48e-4,-16.000001 0.25,5e-6 -3.48e-4,16.000001 z" />
    </g>
  </g>
  <g
     inkscape:groupmode="layer"
     id="Segment D"
     inkscape:label="Segment D"
     style="display:inline">
    <g
       inkscape:groupmode="layer"
       id="Segment D Closed"
       inkscape:label="Segment D Closed"
       style="display:inline">
      <path
         id="segment d0"
         style="display:inline;fill:#000000;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none;stroke-opacity:1"
         d="M 54.499994,112.50002 H 5.5 L 16.500001,101.5 h 26.999993 z"
         inkscape:label="segment d0" />
      <path
         id="segment d1"
         style="display:inline;fill:#f2f2f2;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none;stroke-opacity:1"
         d="m 16.910156,102.5 -8.9804685,8.98046 H 52.050781 L 43.070312,102.5 Z"
         inkscape:label="segment d1" />
    </g>
    <g
       inkscape:groupmode="layer"
       id="Segment D Open"
       inkscape:label="Segment D Open">
      <rect
         style="display:inline;fill:#0d0d0d;fill-opacity:1;stroke:#080808;stroke-width:0"
         id="segment d2"
         width="49"
         height="4"
         x="5.5"
         y="113.5"
         inkscape:label="segment d2" />
      <path
         id="segment d3"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment d3"
         d="m 22.000236,105.49896 15.999999,9.5e-4 -4.75e-4,8 -15.999998,-9.5e-4 z" />
      <path
         id="segment d6"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment d6"
         d="m 38.000235,105.49991 3.000001,1.8e-4 -4.75e-4,8 -3.000001,-1.8e-4 z" />
      <path
         id="segment d5"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment d5"
         d="m 19.000236,105.49878 3,1.8e-4 -4.74e-4,8 -3,-1.8e-4 z" />
      <path
         id="segment d7"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment d7"
         d="m 21.999804,112.7495 16.000001,9.5e-4 -4.4e-5,0.74946 -16,-9.5e-4 z" />
      <path
         id="segment d8"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment d8"
         d="m 21.990158,110.75005 16,9.5e-4 -5.9e-5,0.99945 -16,-9.5e-4 z" />
      <path
         id="segment d9"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment d9"
         d="m 22.000043,108.75059 16,9.5e-4 -6e-5,0.99945 -16,-9.4e-4 z" />
      <path
         id="segment d10"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment d10"
         d="m 22.000162,106.75113 16.000001,9.5e-4 -6e-5,0.99946 -16,-9.5e-4 z" />
      <path
         id="segment d11"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment d11"
         d="m 22.000236,105.4995 16,9.5e-4 -1.5e-5,0.25 -16.000001,-9.5e-4 z" />
    </g>
  </g>
  <g
     inkscape:groupmode="layer"
     id="Segment C"
     inkscape:label="Segment C"
     style="display:inline">
    <g
       inkscape:groupmode="layer"
       id="Segment C Closed"
       inkscape:label="Segment C Closed"
       style="display:inline">
      <path
         id="segment c0"
         style="display:inline;fill:#000000;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none;stroke-opacity:1"
         d="M 44,101.00021 V 67.5 H 55 V 112 Z"
         inkscape:label="segment c0" />
      <path
         id="segment c1"
         style="display:inline;fill:#f2f2f2;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none;stroke-opacity:1"
         d="m 45,68.5 v 32.07031 l 8.980468,8.98047 V 68.5 Z"
         inkscape:label="segment c1" />
    </g>
    <g
       inkscape:groupmode="layer"
       id="Segment C Open"
       inkscape:label="Segment C Open"
       style="display:inline">
      <path
         id="segment c2"
         style="display:inline;fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         d="m 56,67.5 h 4 V 112 h -4 z"
         inkscape:label="segment c2" />
      <path
         id="segment c3"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment c3"
         d="m 56.000066,81.749961 3.46e-4,15.999999 -7.999998,1.75e-4 -3.5e-4,-15.999998 z" />
      <path
         id="segment c6"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment c6"
         d="m 56.000412,97.74996 6.6e-5,3 -8,1.8e-4 -6.4e-5,-3.000005 z" />
      <path
         id="segment c5"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment c5"
         d="m 56,78.749961 6.6e-5,3 -8.000002,1.76e-4 -6.4e-5,-3 z" />
      <path
         id="segment c7"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment c7"
         d="m 48.749524,81.750118 3.5e-4,16.000001 -0.74946,1.7e-5 -3.5e-4,-16 z" />
      <path
         id="segment c8"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment c8"
         d="m 50.748973,81.74031 3.5e-4,16 -0.99945,2.2e-5 -3.5e-4,-16 z" />
      <path
         id="segment c9"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment c9"
         d="m 52.748434,81.750032 3.5e-4,16 -0.99945,2.1e-5 -3.6e-4,-16 z" />
      <path
         id="segment c10"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment c10"
         d="m 54.747896,81.749989 3.46e-4,16.000001 -0.99946,2.1e-5 -3.46e-4,-16 z" />
      <path
         id="segment c11"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment c11"
         d="m 55.999526,81.749961 3.46e-4,16 -0.25,5e-6 -3.46e-4,-16.000001 z" />
    </g>
  </g>
  <g
     inkscape:groupmode="layer"
     id="Segment B"
     inkscape:label="Segment B"
     style="display:inline">
    <g
       inkscape:groupmode="layer"
       id="Segment B Closed"
       inkscape:label="Segment B Closed"
       style="display:inline">
      <path
         id="segment b0"
         style="display:inline;fill:#000000;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none;stroke-opacity:1"
         d="M 44,33.499791 V 67.000015 H 55 V 22.5 Z"
         inkscape:label="segment b0" />
      <path
         id="segment b1"
         style="display:inline;fill:#f2f2f2;fill-opacity:1;stroke:none;stroke-width:0;stroke-dasharray:none;stroke-opacity:1"
         d="M 53.980468,24.929687 45,33.910156 v 32.070312 h 8.980468 z"
         inkscape:label="segment b1" />
    </g>
    <g
       inkscape:groupmode="layer"
       id="Segment B Open"
       inkscape:label="Segment B Open"
       style="display:inline">
      <path
         id="segment b2"
         style="display:inline;fill:#0d0d0d;fill-opacity:1;stroke-width:0"
         d="m 56,22.5 h 4 V 67 h -4 z"
         inkscape:label="segment b2" />
      <path
         id="segment b3"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment b3"
         d="m 56.000066,36.749996 3.46e-4,15.999999 -7.999998,1.75e-4 -3.5e-4,-15.999998 z" />
      <path
         id="segment b6"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment b6"
         d="m 56.000412,52.749995 6.6e-5,3.000001 -8,1.75e-4 -6.4e-5,-3.000001 z" />
      <path
         id="segment b5"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment b5"
         d="m 56,33.749996 6.6e-5,3 -8.000002,1.76e-4 -6.4e-5,-3 z" />
      <path
         id="segment b7"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment b7"
         d="m 48.749524,36.750153 3.5e-4,16.000001 -0.74946,1.7e-5 -3.5e-4,-16 z" />
      <path
         id="segment b8"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment b8"
         d="m 50.748973,36.740345 3.5e-4,16 -0.99945,2.2e-5 -3.5e-4,-16 z" />
      <path
         id="segment b9"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment b9"
         d="m 52.748434,36.750067 3.5e-4,16 -0.99945,2.1e-5 -3.6e-4,-16 z" />
      <path
         id="segment b10"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment b10"
         d="m 54.747896,36.750024 3.46e-4,16.000001 -0.99946,2.1e-5 -3.46e-4,-16 z" />
      <path
         id="segment b11"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment b11"
         d="m 55.999526,36.749996 3.46e-4,16 -0.25,5e-6 L 55.749526,36.75 Z" />
    </g>
  </g>
  <g
     inkscape:groupmode="layer"
     id="Segment A"
     inkscape:label="Segment A"
     style="display:inline">
    <g
       inkscape:groupmode="layer"
       id="Segment A Closed"
       inkscape:label="Segment A Closed"
       style="display:inline">
      <path
         id="segment a0"
         style="display:inline;fill:#000000;fill-opacity:1;stroke:none;stroke-width:0;stroke-linejoin:miter;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1;paint-order:normal"
         d="m 5.5,22 h 49.000003 l -11,11.000001 H 16.5 Z"
         inkscape:label="segment a0" />
      <path
         id="segment a1"
         style="display:inline;fill:#f2f2f2;fill-opacity:1;stroke:none;stroke-width:0;stroke-linejoin:miter;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1;paint-order:normal"
         d="m 7.9296875,23 8.9804685,8.980468 H 43.070312 L 52.050781,23 Z"
         inkscape:label="segment a1" />
    </g>
    <g
       inkscape:groupmode="layer"
       id="Segment A Open"
       inkscape:label="Segment A Open"
       style="display:inline">
      <rect
         style="display:inline;fill:#0d0d0d;fill-opacity:1;stroke:#080808;stroke-width:0"
         id="segment a2"
         width="49"
         height="4"
         x="5.5"
         y="17"
         inkscape:label="segment a2" />
      <path
         id="segment a3"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment a3"
         d="m 22.000239,21.00018 15.999998,9.62e-4 -4.79e-4,7.999998 -15.999997,-9.58e-4 z" />
      <path
         id="segment a6"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment a6"
         d="m 38.000237,21.001142 3.000001,1.79e-4 -4.79e-4,8 -3.000001,-1.81e-4 z" />
      <path
         id="segment a5"
         style="display:inline;fill:#0d0d0d;stroke:#080808;stroke-width:0"
         inkscape:label="segment a5"
         d="m 19.000239,21 3,1.8e-4 -4.78e-4,8.000002 -3,-1.82e-4 z" />
      <path
         id="segment a7"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment a7"
         d="m 21.999803,28.250722 16.000001,9.58e-4 -4.5e-5,0.74946 -15.999999,-9.58e-4 z" />
      <path
         id="segment a8"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment a8"
         d="m 21.990158,26.251272 16,9.58e-4 -6e-5,0.99945 -15.999999,-9.58e-4 z" />
      <path
         id="segment a9"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment a9"
         d="m 22.000044,24.251812 16,9.58e-4 -6.1e-5,0.99945 -16,-9.48e-4 z" />
      <path
         id="segment a10"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment a10"
         d="m 22.000164,22.25235 16.000001,9.62e-4 -6.1e-5,0.99946 -16,-9.62e-4 z" />
      <path
         id="segment a11"
         style="display:inline;fill:#1a1a1a;stroke:#080808;stroke-width:0"
         inkscape:label="segment a11"
         d="m 22.000239,21.00072 15.999999,9.62e-4 -1.5e-5,0.25 -16.000001,-9.62e-4 z" />
    </g>
  </g>
</svg>

)rawliteral";

const char MAIN_page[] PROGMEM = R"rawliteral(


<!DOCTYPE html>
<html>
<head>
  <title>7-Segment Display</title>
  <style>
    body {
      background: #ccc;
      color: white;
      font-family: sans-serif;
      text-align: center;
      margin-top: 40px;
    }

    .display-outer {
      width: 100vw;
      min-height: 1px;
      display: flex;
      justify-content: center;
      align-items: flex-start;
      padding-left: 12px;
      padding-right: calc(12px + 0.7%);
      box-sizing: border-box;
      overflow-x: hidden;
      padding-top: 24px;
      padding-bottom: 24px;
    }

    .display-container {
      position: relative;
      width: 100%;
      max-width: 1000px;
      margin: 5% auto 5% auto;
      overflow: visible;
      box-sizing: border-box;
      aspect-ratio: 289.06244 / 120;
      height: auto;
    }

    .baseplate-bg {
      position: absolute;
      top: 31%;
      left: -0.7%;
      width: 100%;
      height: auto;
      z-index: 0;
      margin-top: 0;
      text-align: center;
      display: block;
    }

    .digits-row {
      position: absolute;
      top: 0;
      left: 0;
      width: 100%;
      height: 100%;
      z-index: 1;
      display: flex;
      align-items: center;
      margin: 0;
    }

    .digit, .space-5, .space-25 {
      flex-shrink: 0;
      flex-grow: 0;
      min-width: 0;
      max-width: none;
    }

    .digit {
      flex: 0 0 21.05%;
      width: auto;
      display: flex;
      align-items: center;
      justify-content: center;
    }

    .digit svg {
      width: 100%;
      height: auto;
      display: block;
    }

    .space-5 {
      flex: 0 0 1.75%;
    }

    .space-25 {
      flex: 0 0 8.77%;
    }

    button {
      padding: 5px 8px;
      font-size: 16px;
      background: #222;
      color: white;
      border: 1px solid #444;
      border-radius: 4px;
      cursor: pointer;
    }
    button:hover {
      background: #333;
    }
    /* Hide all segments by default */
    [id^="segment-"],
    [id^="segment_"] {
      display: none;
    }

    .modules-container {
      display: flex;
      flex-wrap: wrap;
      justify-content: center;
      gap: 24px;
      margin-top: 40px;
    }
    .module-card {
      background: #222;
      color: #fff;
      border-radius: 12px;
      box-shadow: 0 2px 8px #0002;
      padding: 20px 24px;
      min-width: 220px;
      max-width: 260px;
      border: 2px solid transparent;
      transition: border 0.2s, box-shadow 0.2s;
      display: flex;
      flex-direction: column;
      align-items: flex-start;
    }
    .module-card.active {
      border: 2px solid #4af;
      box-shadow: 0 4px 16px #4af4;
    }
    .module-card h3 {
      margin-top: 0;
    }
    .module-card button {
      margin-bottom: 12px;
      align-self: flex-end;
    }

    .timer-inputs {
      display: flex;
      gap: 16px;
      margin-bottom: 12px;
      justify-content: center;
    }
    .timer-col {
      display: flex;
      flex-direction: column;
      align-items: center;
    }
    .timer-col label {
      margin-bottom: 4px;
      font-weight: bold;
    }
    .timer-col input[type="number"] {
      width: 60px;
      font-size: 1.2em;
      text-align: center;
      -moz-appearance: textfield;
    }
    .timer-col input[type="number"]::-webkit-outer-spin-button,
    .timer-col input[type="number"]::-webkit-inner-spin-button {
      -webkit-appearance: none;
      margin: 0;
    }

    .timer-buttons {
      display: flex;
      gap: 12px;
      justify-content: center;
      width: 100%;
    }
  </style>
</head>
<body>
  <h1>7-Segment Display Test</h1>
  <div class="display-outer">
    <div class="display-container">
      <div class="baseplate-bg" id="baseplateContainer"></div>
      <div class="digits-row" id="display"></div>
    </div>
  </div>

  <div class="modules-container">
    <div class="module-card active" data-module="clock">
      <h3>Clock</h3>
      <label>12hr/24hr: <input type="radio" name="timeFormat" value="12hr" checked>12hr <input type="radio" name="timeFormat" value="24hr">24hr</label>
      <label>Timezone: <select id="timezone">
        <option value="UTC">UTC</option>
        <option value="America/New_York">New York (UTC-5/UTC-4)</option>
        <option value="America/Chicago">Chicago (UTC-6/UTC-5)</option>
        <option value="America/Chicago">Lafayette, LA (UTC-6/UTC-5)</option>
        <option value="America/Chicago">Houston, TX (UTC-6/UTC-5)</option>
        <option value="America/Denver">Denver, CO (UTC-7/UTC-6)</option>
        <option value="America/Los_Angeles">Los Angeles (UTC-8/UTC-7)</option>
        <option value="America/Los_Angeles">Portland, OR (UTC-8/UTC-7)</option>
        <option value="America/Anchorage">Anchorage (UTC-9/UTC-8)</option>
        <option value="Pacific/Honolulu">Honolulu (UTC-10)</option>
        <option value="America/Sao_Paulo">Sao Paulo (UTC-3)</option>
        <option value="Europe/London">London (UTC+0/UTC+1)</option>
        <option value="Europe/Paris">Paris (UTC+1/UTC+2)</option>
        <option value="Europe/Moscow">Moscow (UTC+3)</option>
        <option value="Africa/Cairo">Cairo (UTC+2)</option>
        <option value="Asia/Dubai">Dubai (UTC+4)</option>
        <option value="Asia/Kolkata">Mumbai (UTC+5:30)</option>
        <option value="Asia/Bangkok">Bangkok (UTC+7)</option>
        <option value="Asia/Hong_Kong">Hong Kong (UTC+8)</option>
        <option value="Asia/Tokyo">Tokyo (UTC+9)</option>
        <option value="Australia/Sydney">Sydney (UTC+10/UTC+11)</option>
        <option value="Pacific/Auckland">Auckland (UTC+12/UTC+13)</option>
        <option value="Pacific/Auckland">Christchurch, NZ (UTC+12/UTC+13)</option>
      </select></label>
    </div>
    <div class="module-card" data-module="timer">
      <h3>Timer</h3>
      <div class="timer-inputs">
        <div class="timer-col">
          <label>Minutes</label>
          <input type="number" min="0" max="99" value="5" class="timer-minutes">
        </div>
        <div class="timer-col">
          <label>Seconds</label>
          <input type="number" min="0" max="59" value="30" class="timer-seconds">
        </div>
      </div>
      <div class="timer-buttons">
        <button class="timer-start">Start</button>
        <button class="timer-stop" disabled>Stop</button>
        <button class="timer-reset">Reset</button>
      </div>
    </div>
    <div class="module-card" data-module="stopwatch">
      <h3>Stopwatch</h3>
      <div class="stopwatch-buttons">
        <button class="stopwatch-start">Start</button>
        <button class="stopwatch-stop" disabled>Stop</button>
        <button class="stopwatch-reset">Reset</button>
      </div>
    </div>
    <div class="module-card" data-module="dice">
      <h3>Dice Simulator</h3>
      <div class="dice-row" style="display: flex; gap: 32px; justify-content: center; align-items: flex-end; margin-bottom: 12px;">
        <div class="dice-col" style="display: flex; flex-direction: column; align-items: center;">
          <div style="font-weight: bold; margin-bottom: 4px;">Left</div>
          <select class="dice-left-select"></select>
        </div>
        <div class="dice-col" style="display: flex; flex-direction: column; align-items: center;">
          <div style="font-weight: bold; margin-bottom: 4px;">Right</div>
          <select class="dice-right-select"></select>
        </div>
      </div>
      <div style="display: flex; justify-content: center;">
        <button class="dice-roll">Roll</button>
      </div>
    </div>
    <div class="module-card" data-module="temp">
      <h3>Temperature</h3>
      <div style="display: flex; flex-direction: column; gap: 8px; align-items: flex-start; width: 100%;">
        <div style="display: flex; gap: 8px; width: 100%;">
          <input type="text" class="temp-location-input" placeholder="Enter location..." style="flex: 1; min-width: 0;">
          <button class="temp-search">Search</button>
        </div>
        <div style="margin-top: 4px;">
          <label><input type="radio" name="temp-unit" value="F" checked> °F</label>
          <label style="margin-left: 12px;"><input type="radio" name="temp-unit" value="C"> °C</label>
        </div>
        <div class="temp-status" style="font-size: 0.95em; color: #aaa; min-height: 1.5em;"></div>
      </div>
    </div>
    <div class="module-card" data-module="pattern">
      <h3>Animated Patterns</h3>
      <label>Pattern: 
        <select>
          <option value="wave">Wave</option>
          <option value="count">Count Up</option>
          <option value="random">Random</option>
        </select>
      </label>
    </div>
  </div>

  <script>
  (async function () {
      const resp = await fetch('/7segdigit.svg');
      const svg = await resp.text();

      const baseResp = await fetch('/clockbaseplate.svg');
      const baseSvg = await baseResp.text();
      document.getElementById('baseplateContainer').innerHTML = baseSvg;
    
    const segmentMap = {
      0: ['a', 'b', 'c', 'd', 'e', 'f'],
      1: ['b', 'c'],
      2: ['a', 'b', 'g', 'e', 'd'],
      3: ['a', 'b', 'g', 'c', 'd'],
      4: ['f', 'g', 'b', 'c'],
      5: ['a', 'f', 'g', 'c', 'd'],
      6: ['a', 'f', 'g', 'e', 'c', 'd'],
      7: ['a', 'b', 'c'],
      8: ['a', 'b', 'c', 'd', 'e', 'f', 'g'],
      9: ['a', 'b', 'c', 'd', 'f', 'g']
    };

    function setDigit(svgEl, number) {
      svgEl.setAttribute('data-digit', number);  // ← Add this line
      const active = segmentMap[number];
      ['a','b','c','d','e','f','g'].forEach(letter => {
        const group = svgEl.getElementById('Segment ' + letter.toUpperCase());
        if (group) {
          const closed = group.querySelector('[id^="Segment ' + letter.toUpperCase() + ' Closed"]');
          const open = group.querySelector('[id^="Segment ' + letter.toUpperCase() + ' Open"]');
          const isOn = active.includes(letter);
          if (closed) closed.style.display = isOn ? 'inline' : 'none';
          if (open) open.style.display = isOn ? 'none' : 'inline';
        }
      });
    }


    // Create the 4 digit elements
    const display = document.getElementById('display');
    display.innerHTML = '';
    // Add left padding
    const leftPad = document.createElement('div');
    leftPad.className = 'space space-5';
    display.appendChild(leftPad);
    for (let i = 0; i < 4; i++) {
      if (i === 1) {
        const space5 = document.createElement('div');
        space5.className = 'space space-5';
        display.appendChild(space5);
      }
      if (i === 2) {
        const space25 = document.createElement('div');
        space25.className = 'space space-25';
        display.appendChild(space25);
      }
      if (i === 3) {
        const space5b = document.createElement('div');
        space5b.className = 'space space-5';
        display.appendChild(space5b);
      }
      const container = document.createElement('div');
      container.classList.add('digit');
      container.innerHTML = svg;
      // Ensure supports are always visible
      const svgEl = container.querySelector('svg');
      showSegmentSupports(svgEl);
      display.appendChild(container);
    }
    // Add right padding
    const rightPad = document.createElement('div');
    rightPad.className = 'space space-5';
    display.appendChild(rightPad);

    // Card selection logic
    document.querySelectorAll('.module-card').forEach(card => {
      card.addEventListener('click', function() {
        document.querySelectorAll('.module-card').forEach(c => c.classList.remove('active'));
        card.classList.add('active');
        // Update clock immediately if switching to clock
        if (card.dataset.module === 'clock') updateClock();
      });
    });

    // Helper: get selected timezone offset in hours
    function getTimezoneOffset(tz) {
      switch (tz) {
        case 'EST': return -5;
        case 'CST': return -6;
        case 'MST': return -7;
        case 'PST': return -8;
        case 'UTC':
        default: return 0;
      }
    }

    // Helper: get selected time format (12hr/24hr)
    function getTimeFormat() {
      const checked = document.querySelector('input[name="timeFormat"]:checked');
      return checked ? checked.value : '24hr';  // fallback to 24hr
    }

    // Helper: get selected timezone
    function getSelectedTimezone() {
      const sel = document.getElementById('timezone');
      return sel ? sel.value : 'UTC';
    }

    // Update display with current time every 2 seconds
    function updateClock() {
      // Only update if Clock card is active
      const clockCard = document.querySelector('.module-card[data-module="clock"]');
      if (!clockCard.classList.contains('active')) return;

      const tz = getSelectedTimezone();
      const format = getTimeFormat();
      const now = new Date();
      const options = { hour: '2-digit', minute: '2-digit', hour12: format === '12hr', timeZone: tz };
      const parts = new Intl.DateTimeFormat('en-US', options).formatToParts(now);
      let hours = parts.find(p => p.type === 'hour').value;
      let minutes = parts.find(p => p.type === 'minute').value;
      // Pad hours/minutes if needed
      hours = hours.toString().padStart(2, '0');
      minutes = minutes.toString().padStart(2, '0');
      const timeStr = hours + minutes;

      const digits = document.querySelectorAll('.digit');
      for (let i = 0; i < 4; i++) {
        const svgEl = digits[i].querySelector('svg');
        setDigit(svgEl, parseInt(timeStr[i]));
      }
      updateHardwareDigits();
    }

    // Listen for changes to format/timezone
    document.querySelectorAll('input[name="timeFormat"]').forEach(radio => {
      radio.addEventListener('change', updateClock);
    });
    const tzSel = document.getElementById('timezone');
    if (tzSel) tzSel.addEventListener('change', updateClock);

    setInterval(updateClock, 2000);
    updateClock(); // Run once immediately

    let timerInterval = null;
    let timerRemaining = 0;
    let timerPaused = false;
    let timerInitial = 0;

    function getTimerCard() {
      return document.querySelector('.module-card[data-module="timer"]');
    }
    function getTimerMinutesInput() {
      return getTimerCard().querySelector('.timer-minutes');
    }
    function getTimerSecondsInput() {
      return getTimerCard().querySelector('.timer-seconds');
    }
    function getTimerStartBtn() {
      return getTimerCard().querySelector('.timer-start');
    }
    function getTimerStopBtn() {
      return getTimerCard().querySelector('.timer-stop');
    }
    function getTimerResetBtn() {
      return getTimerCard().querySelector('.timer-reset');
    }

    function updateTimerDisplay() {
      const timerCard = getTimerCard();
      if (!timerCard.classList.contains('active')) return;
      let minutes = Math.floor(timerRemaining / 60);
      let seconds = timerRemaining % 60;
      minutes = Math.max(0, minutes);
      seconds = Math.max(0, seconds);
      const minStr = minutes.toString().padStart(2, '0');
      const secStr = seconds.toString().padStart(2, '0');
      const timeStr = minStr + secStr;
      const digits = document.querySelectorAll('.digit');
      for (let i = 0; i < 4; i++) {
        const svgEl = digits[i].querySelector('svg');
        setDigit(svgEl, parseInt(timeStr[i]));
      }
      updateHardwareDigits();
    }

    function startTimerCountdown() {
      if (timerInterval) clearInterval(timerInterval);
      getTimerMinutesInput().disabled = true;
      getTimerSecondsInput().disabled = true;
      getTimerStopBtn().disabled = false;
      getTimerResetBtn().disabled = false;
      const startBtn = getTimerStartBtn();
      startBtn.textContent = 'Pause';
      startBtn.disabled = false;
      timerPaused = false;
      timerInterval = setInterval(() => {
        if (!timerPaused && timerRemaining > 0) {
          timerRemaining--;
          updateTimerDisplay();
        } else if (!timerPaused && timerRemaining <= 0) {
          clearInterval(timerInterval);
          timerInterval = null;
          getTimerMinutesInput().disabled = false;
          getTimerSecondsInput().disabled = false;
          getTimerStartBtn().textContent = 'Start';
          getTimerStartBtn().disabled = false;
          getTimerStopBtn().disabled = true;
          getTimerResetBtn().disabled = false;
          updateTimerDisplay();
          // Start wave animation
          startTimerWaveAnimation();
        }
      }, 1000);
    }

    // Timer wave animation: flip each digit to 1, then next, then next, then next, then reset all to 0
    function startTimerWaveAnimation() {
      const digits = document.querySelectorAll('.digit');
      let waveStep = 0;
      let waveRepeat = 0;
      const waveStates = [
        [1,0,0,0],
        [0,1,0,0],
        [0,0,1,0],
        [0,0,0,1],
        [0,0,0,0]
      ];
      function setWaveDigits(state) {
        for (let i = 0; i < 4; i++) {
          const svgEl = digits[i].querySelector('svg');
          setDigit(svgEl, state[i]);
        }
      }
      setWaveDigits(waveStates[0]);
      let waveInterval = setInterval(() => {
        waveStep++;
        if (waveStep < waveStates.length) {
          setWaveDigits(waveStates[waveStep]);
        } else {
          waveStep = 0;
          waveRepeat++;
          if (waveRepeat < 5) {
            setWaveDigits(waveStates[waveStep]);
          } else {
            clearInterval(waveInterval);
            updateTimerDisplay(); // restore timer display (should be 0)
          }
        }
      }, 180);
    }

    function pauseTimerCountdown() {
      timerPaused = true;
      getTimerStartBtn().textContent = 'Start';
    }

    function stopTimerCountdown() {
      if (timerInterval) clearInterval(timerInterval);
      timerInterval = null;
      timerPaused = false;
      getTimerMinutesInput().disabled = false;
      getTimerSecondsInput().disabled = false;
      getTimerStartBtn().textContent = 'Start';
      getTimerStartBtn().disabled = false;
      getTimerStopBtn().disabled = true;
      getTimerResetBtn().disabled = false;
      timerRemaining = timerInitial;
      updateTimerDisplay();
    }

    function resetTimerCountdown() {
      if (timerInterval) clearInterval(timerInterval);
      timerInterval = null;
      timerPaused = false;
      getTimerMinutesInput().disabled = false;
      getTimerSecondsInput().disabled = false;
      getTimerStartBtn().textContent = 'Start';
      getTimerStartBtn().disabled = false;
      getTimerStopBtn().disabled = true;
      getTimerResetBtn().disabled = false;
      const min = parseInt(getTimerMinutesInput().value, 10) || 0;
      const sec = parseInt(getTimerSecondsInput().value, 10) || 0;
      timerRemaining = min * 60 + sec;
      timerInitial = timerRemaining;
      updateTimerDisplay();
    }

    const timerCard = getTimerCard();
    timerCard.addEventListener('click', function(e) {
      // Only trigger if clicking the card, not a button
      if (e.target.closest('button')) return;
      if (timerInterval) clearInterval(timerInterval);
      timerInterval = null;
      timerPaused = false;
      getTimerMinutesInput().disabled = false;
      getTimerSecondsInput().disabled = false;
      getTimerStartBtn().textContent = 'Start';
      getTimerStartBtn().disabled = false;
      getTimerStopBtn().disabled = true;
      getTimerResetBtn().disabled = false;
      const min = parseInt(getTimerMinutesInput().value, 10) || 0;
      const sec = parseInt(getTimerSecondsInput().value, 10) || 0;
      timerRemaining = min * 60 + sec;
      timerInitial = timerRemaining;
      updateTimerDisplay();
    });

    timerCard.querySelector('.timer-buttons').addEventListener('click', function(e) {
      if (e.target.classList.contains('timer-start')) {
        if (getTimerStartBtn().textContent === 'Pause') {
          pauseTimerCountdown();
        } else {
          if (!timerPaused) {
            const min = parseInt(getTimerMinutesInput().value, 10) || 0;
            const sec = parseInt(getTimerSecondsInput().value, 10) || 0;
            timerRemaining = min * 60 + sec;
            timerInitial = timerRemaining;
          }
          startTimerCountdown();
        }
      } else if (e.target.classList.contains('timer-stop')) {
        stopTimerCountdown();
      } else if (e.target.classList.contains('timer-reset')) {
        resetTimerCountdown();
      }
    });

    // Update main updateClock to not overwrite timer when timer is active
    const originalUpdateClock = updateClock;
    window.updateClock = function() {
      const timerCard = document.querySelector('.module-card[data-module="timer"]');
      if (timerCard.classList.contains('active')) {
        updateTimerDisplay();
        return;
      }
      originalUpdateClock();
    };

    let stopwatchInterval = null;
    let stopwatchElapsed = 0;
    let stopwatchPaused = false;

    function getStopwatchCard() {
      return document.querySelector('.module-card[data-module="stopwatch"]');
    }
    function getStopwatchStartBtn() {
      return getStopwatchCard().querySelector('.stopwatch-start');
    }
    function getStopwatchStopBtn() {
      return getStopwatchCard().querySelector('.stopwatch-stop');
    }
    function getStopwatchResetBtn() {
      return getStopwatchCard().querySelector('.stopwatch-reset');
    }

    function updateStopwatchDisplay() {
      const stopwatchCard = getStopwatchCard();
      if (!stopwatchCard.classList.contains('active')) return;
      let minutes = Math.floor(stopwatchElapsed / 60);
      let seconds = stopwatchElapsed % 60;
      minutes = Math.min(99, Math.max(0, minutes));
      seconds = Math.max(0, seconds);
      const minStr = minutes.toString().padStart(2, '0');
      const secStr = seconds.toString().padStart(2, '0');
      const timeStr = minStr + secStr;
      const digits = document.querySelectorAll('.digit');
      for (let i = 0; i < 4; i++) {
        const svgEl = digits[i].querySelector('svg');
        setDigit(svgEl, parseInt(timeStr[i]));
      }
      updateHardwareDigits();
    }

    function startStopwatch() {
      if (stopwatchInterval) clearInterval(stopwatchInterval);
      getStopwatchStartBtn().textContent = 'Pause';
      getStopwatchStartBtn().disabled = false;
      getStopwatchStopBtn().disabled = false;
      getStopwatchResetBtn().disabled = false;
      stopwatchPaused = false;
      stopwatchInterval = setInterval(() => {
        if (!stopwatchPaused) {
          stopwatchElapsed++;
          if (stopwatchElapsed > 5999) stopwatchElapsed = 0; // Max 99:59
          updateStopwatchDisplay();
        }
      }, 1000);
    }

    function pauseStopwatch() {
      stopwatchPaused = true;
      getStopwatchStartBtn().textContent = 'Start';
    }

    function stopStopwatch() {
      if (stopwatchInterval) clearInterval(stopwatchInterval);
      stopwatchInterval = null;
      stopwatchPaused = false;
      getStopwatchStartBtn().textContent = 'Start';
      getStopwatchStartBtn().disabled = false;
      getStopwatchStopBtn().disabled = true;
      getStopwatchResetBtn().disabled = false;
    }

    function resetStopwatch() {
      if (stopwatchInterval) clearInterval(stopwatchInterval);
      stopwatchInterval = null;
      stopwatchPaused = false;
      stopwatchElapsed = 0;
      getStopwatchStartBtn().textContent = 'Start';
      getStopwatchStartBtn().disabled = false;
      getStopwatchStopBtn().disabled = true;
      getStopwatchResetBtn().disabled = false;
      updateStopwatchDisplay();
    }

    const stopwatchCard = getStopwatchCard();
    stopwatchCard.addEventListener('click', function(e) {
      // Only trigger if clicking the card, not a button
      if (e.target.closest('button')) return;
      if (stopwatchInterval) clearInterval(stopwatchInterval);
      stopwatchInterval = null;
      stopwatchPaused = false;
      stopwatchElapsed = 0;
      getStopwatchStartBtn().textContent = 'Start';
      getStopwatchStartBtn().disabled = false;
      getStopwatchStopBtn().disabled = true;
      getStopwatchResetBtn().disabled = false;
      updateStopwatchDisplay();
    });

    stopwatchCard.querySelector('.stopwatch-buttons').addEventListener('click', function(e) {
      if (e.target.classList.contains('stopwatch-start')) {
        if (getStopwatchStartBtn().textContent === 'Pause') {
          pauseStopwatch();
        } else {
          startStopwatch();
        }
      } else if (e.target.classList.contains('stopwatch-stop')) {
        stopStopwatch();
      } else if (e.target.classList.contains('stopwatch-reset')) {
        resetStopwatch();
      }
    });

    // Update main updateClock to not overwrite stopwatch when stopwatch is active
    const origUpdateClock = window.updateClock;
    window.updateClock = function() {
      const stopwatchCard = document.querySelector('.module-card[data-module="stopwatch"]');
      if (stopwatchCard && stopwatchCard.classList.contains('active')) {
        updateStopwatchDisplay();
        return;
      }
      origUpdateClock();
    };

    // Dice Simulator logic
    function fillDiceSelectOptions(select) {
      select.innerHTML = '';
      const dash = document.createElement('option');
      dash.value = '-';
      dash.textContent = '-';
      select.appendChild(dash);
      for (let i = 2; i <= 99; i++) {
        const opt = document.createElement('option');
        opt.value = 'd' + i;
        opt.textContent = 'd' + i;
        select.appendChild(opt);
      }
    }

    const diceCard = document.querySelector('.module-card[data-module="dice"]');
    const diceLeftSelect = diceCard.querySelector('.dice-left-select');
    const diceRightSelect = diceCard.querySelector('.dice-right-select');
    const diceRollBtn = diceCard.querySelector('.dice-roll');
    fillDiceSelectOptions(diceLeftSelect);
    fillDiceSelectOptions(diceRightSelect);

    diceRollBtn.addEventListener('click', function() {
      // Only roll if Dice card is active
      if (!diceCard.classList.contains('active')) return;
      const leftType = diceLeftSelect.value;
      const rightType = diceRightSelect.value;
      let leftVal = 0, rightVal = 0;
      if (leftType !== '-') {
        const max = parseInt(leftType.slice(1), 10);
        leftVal = Math.floor(Math.random() * max) + 1;
      }
      if (rightType !== '-') {
        const max = parseInt(rightType.slice(1), 10);
        rightVal = Math.floor(Math.random() * max) + 1;
      }
      // Format as two digits each
      const leftStr = leftType === '-' ? '00' : leftVal.toString().padStart(2, '0');
      const rightStr = rightType === '-' ? '00' : rightVal.toString().padStart(2, '0');
      const digits = document.querySelectorAll('.digit');
      // Left die: first two digits, right die: last two digits
      for (let i = 0; i < 2; i++) {
        const svgEl = digits[i].querySelector('svg');
        setDigit(svgEl, parseInt(leftStr[i]));
      }
      for (let i = 0; i < 2; i++) {
        const svgEl = digits[i+2].querySelector('svg');
        setDigit(svgEl, parseInt(rightStr[i]));
      }
    });

    // When switching to Dice card, show 00 00
    function updateDiceDisplay() {
      const diceCard = document.querySelector('.module-card[data-module="dice"]');
      if (!diceCard.classList.contains('active')) return;
      const digits = document.querySelectorAll('.digit');
      for (let i = 0; i < 4; i++) {
        const svgEl = digits[i].querySelector('svg');
        setDigit(svgEl, 0);
      }
      updateHardwareDigits();
    }
    // Patch updateClock to show 00 00 for dice
    const origUpdateClock2 = window.updateClock;
    window.updateClock = function() {
      const diceCard = document.querySelector('.module-card[data-module="dice"]');
      if (diceCard && diceCard.classList.contains('active')) {
        updateDiceDisplay();
        return;
      }
      origUpdateClock2();
    };

    // Temperature card logic
    const tempCard = document.querySelector('.module-card[data-module="temp"]');
    const tempInput = tempCard.querySelector('.temp-location-input');
    const tempSearchBtn = tempCard.querySelector('.temp-search');
    const tempStatus = tempCard.querySelector('.temp-status');
    const tempUnitRadios = tempCard.querySelectorAll('input[name="temp-unit"]');
    let lastTempData = null;

    async function fetchTemperature(location, unit) {
      tempStatus.textContent = 'Loading...';
      try {
        // Use Open-Meteo Geocoding API to get lat/lon
        const geoResp = await fetch(`https://geocoding-api.open-meteo.com/v1/search?name=${encodeURIComponent(location)}&count=1&language=en&format=json`);
        const geoData = await geoResp.json();
        if (!geoData.results || geoData.results.length === 0) {
          tempStatus.textContent = 'Location not found.';
          return null;
        }
        const { latitude, longitude, name, country } = geoData.results[0];
        // Use Open-Meteo Weather API to get current temperature
        const weatherResp = await fetch(`https://api.open-meteo.com/v1/forecast?latitude=${latitude}&longitude=${longitude}&current_weather=true`);
        const weatherData = await weatherResp.json();
        if (!weatherData.current_weather) {
          tempStatus.textContent = 'Weather data unavailable.';
          return null;
        }
        let tempC = weatherData.current_weather.temperature;
        let tempF = tempC * 9/5 + 32;
        lastTempData = { tempC, tempF, name, country };
        tempStatus.textContent = `Current temperature in ${name}, ${country}`;
        return unit === 'F' ? tempF : tempC;
      } catch (e) {
        tempStatus.textContent = 'Error fetching temperature.';
        return null;
      }
    }

    function updateTempDisplay(temp) {
      const tempCard = document.querySelector('.module-card[data-module="temp"]');
      if (!tempCard.classList.contains('active')) return;
      let value = Math.round(temp);
      value = Math.max(-999, Math.min(999, value));
      let str = '';
      if (Math.abs(value) < 100) {
        // Show on right two digits, left two blank
        str = '  ' + Math.abs(value).toString().padStart(2, '0');
      } else {
        // Show hundreds digit (or minus) on digit 1, tens/ones on right
        const absVal = Math.abs(value);
        const hundreds = Math.floor(absVal / 100);
        const tensOnes = (absVal % 100).toString().padStart(2, '0');
        if (value < 0) {
          str = ' ' + '-' + hundreds.toString() + tensOnes;
        } else {
          str = '  ' + hundreds.toString() + tensOnes;
        }
      }
      str = str.slice(-4); // Ensure 4 chars
      const digits = document.querySelectorAll('.digit');
      for (let i = 0; i < 4; i++) {
        const svgEl = digits[i].querySelector('svg');
        const ch = str[i];
        if (ch === ' ' || ch === undefined) {
          setDigit(svgEl, 0);
        } else if (ch === '-') {
          setDigit(svgEl, 6); // Use 6 as minus hack
        } else {
          setDigit(svgEl, parseInt(ch));
        }
      }
      updateHardwareDigits();
    }

    tempSearchBtn.addEventListener('click', async function() {
      const location = tempInput.value.trim();
      if (!location) {
        tempStatus.textContent = 'Enter a location.';
        return;
      }
      const unit = Array.from(tempUnitRadios).find(r => r.checked).value;
      const temp = await fetchTemperature(location, unit);
      if (temp !== null) updateTempDisplay(temp);
    });

    tempInput.addEventListener('keydown', function(e) {
      if (e.key === 'Enter') tempSearchBtn.click();
    });

    tempUnitRadios.forEach(radio => {
      radio.addEventListener('change', function() {
        if (lastTempData) {
          const unit = Array.from(tempUnitRadios).find(r => r.checked).value;
          updateTempDisplay(unit === 'F' ? lastTempData.tempF : lastTempData.tempC);
        }
      });
    });

    // When switching to Temp card, clear status and display
    function updateTempCardDisplay() {
      const tempCard = document.querySelector('.module-card[data-module="temp"]');
      if (!tempCard.classList.contains('active')) return;
      tempStatus.textContent = '';
      const digits = document.querySelectorAll('.digit');
      for (let i = 0; i < 4; i++) {
        const svgEl = digits[i].querySelector('svg');
        setDigit(svgEl, 0);
      }
    }
    // Patch updateClock to show blank for temp
    const origUpdateClock3 = window.updateClock;
    window.updateClock = function() {
      const tempCard = document.querySelector('.module-card[data-module="temp"]');
      if (tempCard && tempCard.classList.contains('active')) {
        updateTempCardDisplay();
        return;
      }
      origUpdateClock3();
    };

    function showSegmentSupports(svgEl) {
      const supportIds = [
        'Frame',            // The outer frame group
        'Segment_Support', // The support/Frame 1 group
        'Frame_Hinge_Supports',
        'SegmentAGear',
        'SegmentBGear',
        'SegmentCGear',
        'SegmentDGear',
        'SegmenEGear', // typo in SVG, keep as is
        'SegmentFGear',
        'SegmentGGear'
      ];
      supportIds.forEach(id => {
        const el = svgEl.getElementById(id);
        if (el) el.style.display = 'inline';
      });
    }

    function updateHardwareDigits() {
      const digits = document.querySelectorAll('.digit svg');
      let str = '';
      for (let i = 0; i < 4; i++) {
        str += digits[i].getAttribute('data-digit') || '0';
      }
      fetch(`/setDigits?d=${str}`);
    }

})();
  </script>

</body>
</html>


)rawliteral";

WebServer server(80);

void handleRoot() {
  server.send_P(200, "text/html", MAIN_page);  // Serve embedded HTML
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);  // Serve the embedded page

  server.on("/clockbaseplate.svg", []() {
    server.send_P(200, "image/svg+xml", CLOCK_BASE_SVG);
  });

  server.on("/7segdigit.svg", []() {
    server.send_P(200, "image/svg+xml", DIGIT_SVG);
  });

  server.on("/setDigits", []() {
    if (!server.hasArg("d") || server.arg("d").length() != 4) {
      server.send(400, "text/plain", "Invalid digit string");
      return;
    }

    String digits = server.arg("d");
    for (int i = 0; i < 4; i++) {
      char c = digits.charAt(i);
      if (c >= '0' && c <= '9') {
        setServoDigit(i, c - '0');
      }
    }

    server.send(200, "text/plain", "OK");
  });

  Wire.begin(21, 22);  // ESP32 Nano I2C pins
  pca.begin();
  pca.setPWMFreq(50);
  delay(10);

  server.begin();
  Serial.println("HTTP server started.");
}

void loop() {
  server.handleClient();
}
