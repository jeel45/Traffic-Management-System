# Traffic-Management-System
 

Smart Traffic Management System Using Internet of Things

 


 

Abstract— Traffic management system is considered as one of the major dimensions of a smart city. With the rapid growth of population and urban mobility in metropolitan cities, traffic congestion is often seen on roads. To tackle various issues for managing traffic on roads and to help authorities in proper planning, a smart traffic management system using the Internet of Things (IoT) is proposed in this paper. A hybrid approach (combination of centralized and decentralized) is used to optimize traffic flow on roads and an algorithm is devised to manage various traffic situations efficiently. For this purpose, the system takes traffic density as input from a) cameras b) and sensors, then manages traffic signals. Another algorithm based on Artificial Intelligence is used to predict the traffic density for future to minimize the traffic congestion. Besides this, RFIDs are also used to prioritize the emergency vehicles such as ambulances and fire brigade vehicles during a traffic jam. In case of fire on the road, Smoke sensors are also part of this system to detect this situation. To demonstrate the effectiveness of the proposed traffic management system, a prototype is developed which not only optimizes the flow of traffic but also connects nearby rescue departments with a centralized server. Moreover, it also extracts useful information presented in graphical formats that may help the authorities in future road planning.

 

Keywords— IoT, Smart City, Smart Traffic Management, Traffic Congestion, Traffic Signal Management.

INTRODUCTION
A city is a complex system which consists of many interdependent subsystems where traffic system is one of its important subsystems. A study says; it is the cornerstone of the world’s economy. Moreover, it is also declared as one of the major dimensions of the smart city. With the rapid growth of the population of the world, the number of vehicles on roadways is increasing consequently, the rate of traffic jams is also increasing in the same manner. Traffic jams are not just wasting time but in some cases, it is witnessed that criminal activities like mobile snatching at traffic signals also happen in metropolitan cities. On the other hand, it is not only affecting ecosystem badly but the efficiency of industries is also being affected.

It is, therefore, identified that active traffic management is a necessity. In majority countries, traffic is managed through fixed time signals whereas, in large cities of some developed countries, traffic is managed through centrally controlled systems. The paradigm of the Internet of Thing (IoT) has been introduced in traffic management systems.

To the best of our knowledge, it is identified that till date the current traffic management systems are centralized. In case of networking issues, such systems may crash. In addition, there is less focus on fluctuations in traffic flow. Therefore, the proposed system manages the traffic on local and centralized servers by exploiting the concepts of IoT and Artificial Intelligence together. The representation of traffic data in statistical form can also be helpful to authorities for real-time controlling and managing traffic. Moreover, it may also be helpful for future planning.

The rest of the paper is structured in four sections. Section II discusses the state of the art. The proposed system is presented and discussed in Section III whereas a discussion on results is being carried on in Section IV. Section V concludes the research. 

LITERATURE REVIEW
A smart traffic management system that is partially deployed in Cambridge city where queue detectors are buried in the roads that detect the traffic queue and inform the central control unit which takes decision accordingly. Since the system is centralized that can slow down due to networking issues. The researcher used surveillance cameras to detect traffic and OCR to identify the vehicles through number plate recognition which is a simple detection method but the system will fail in Pakistan as there are different kinds of traffic including cycles, donkey carts which have no number plate.

Osman et al. proposed a system in which they have used surveillance cameras to detect traffic density using MATLAB, a traffic controller and a wireless transmitter used to send images to the server after that server calculated traffic density by using those images of every section. This system used fixed (predefined) thresholds that depend on a number of vehicles on road. An algorithm was used to set a time span of red light for a particular lane of the intersection, which is determined by traffic density on road and forwarded to the microcontroller and then server.

Jadhav et al. used surveillance cameras, MATLAB and KEIL (Microcontroller coding) to control traffic congestion. This paper also discusses the priority-based traffic clearance and red signal broker (Number plate detection). Due to using heavy hardware, it is difficult to manage and become costly.    Bui et al. Analyzed a real-time process synchronization based system to manage the traffic flow dynamically. Sensors were used to detect the traffic, where vehicle to vehicle and vehicle to infrastructure communication was done by using wireless communication devices. Controller placed at the center of the intersection received vehicles’ and pedestrians’ information and requests and process using first come first serve method .

Swathi et al. proposed smart traffic routing system that chooses the shortest route having the least congestion. Sensors are used to collect data about traffic density, these sensors use solar energy and battery.  Sensors kept transmitting infrared light and when an object came near, they detect traffic density by monitoring the reflected light from the vehicle. However, readings may change with the change in temperature and humidity. 

Al-Sakran et al. proposed a system in which major goals were detecting vehicles and get their location by using sensors and RFIDs after getting data it sent to centralized controlling center by using a wireless connection for further processing. Researchers used cloud computing, RFIDs, GPS, wireless sensor network (WSN), agent and other modern tools and technologies to collect, store, manage and supervise traffic information.

 

 

PROPOSED SYSTEM
The proposed system, shown in Figure 1, is designed to govern traffic at road networks, sensing through sensors, surveillance cameras, and RFIDs which are embedded on roadsides. The system works in a distributed manner, it processes sensors’ data at the node level and videos’ data at the local server, calculates cumulative density to regulate the traffic according to density. In addition to this, it also tackles emergency vehicles such as ambulance, fire brigade. it also helps the users to know the congestion status at a road through prediction. The system is divided into three layers. A) Data Acquisition and Collection layer. B) Data Processing and Decision-making layer C) Application and Actuation layer.

A. Data Acquisition and Collection Layer
 

Figure 1. The System Model

Several ways of traffic detection have been used by the researchers in the state of the art which consists ultrasonic sensors, RFIDs, surveillance cameras and light beam. All these sources have merits as well as demerits; the suitable sources in the context of the proposed system are surveillance cameras, ultrasonic sensors, RFIDs, smoke sensors and flame sensors. A surveillance camera is the most widely used source to detect the road traffic in this field due to efficiency and ease of maintenance [15] [16] [17] [18]. Blob detection algorithm is applied to the video stream at the local server due to its performance and capability of noise reduction [18]. After traffic detection, a local server sends the density measured through image processing to the respective microcontroller.

 

Apart from the cameras, this system is also using ultrasonic sensors to enhance the accuracy. Sensors are integral part used to detect traffic density in many traffic management system applications [13]. It measures distance by sending out a sound wave of a specific frequency and listening for that sound wave to bounce back. This economical sensor measures the distance 2 cm to 400 cm [19]. The system calculates the distance by using the following formula:

Distance = ((a x b) / 2) a= Speed of sound b= time taken

As shown in Figure 2, there are three pairs of sensors at a certain distance are embedded on each roadside of an intersection to calculate the traffic density. Each sensor’s reading is 1 or 0 (Either that particular sensor detects the vehicle or not). At the node side, density is calculated by considering the readings of all the sensors embedded at that particular roadside.

∑ ( ) = Pi + Pi+1 + Pi+2

P is the pair of ultrasonic sensors. Table 1. shows the states of the sensors and their results are as follow:

TABLE 1. TRAFFIC DENSITY STATES BY ULTRASONIC SENSORS

Condition / Sensors

P1

P2

P3

Status

Condition 1

1

0

0

Low

Condition 2

1

1

0

Medium

Condition 3

1

1

1

High

 

Figure 2. Sensors Network

The microcontroller receives results from sensors and video from a local server to calculate cumulative density using Table 2.

TABLE 2. CUMULATIVE DENSITY

Situations

Sensors’ Result

Camera’s Result

Traffic Density

Situation 1

High

High

High

Situation 2

High

Medium

High

Situation 3

High

Low

Medium

Situation 4

Medium

High

High

Situation 5

Medium

Medium

Medium

Situation 6

Medium

Low

Medium

Situation 7

Low

High

Medium

Situation 8

Low

Medium

Medium

Situation 9

Low

Low

Low

 

B. Data Processing and Decision-Making Layer
The system manages the road traffic according to the traffic condition. a)  In the first situation, each traffic signal has a preset time that is α seconds, when there is normal traffic on road. Every signal is going for green at their turn for α seconds, and rest of signals at that time remains red until all remaining traffic signal at an intersection complete their turn. Traffic ratio is increasing day by day and our current Fixed-time signal control system is not working well in this situation, there is a dire need to add a density based traffic management module which allocates time dynamically to each lane on the base of the traffic density, in second part of algorithm when the capacity of traffic is increased and flow of traffic is not in routine, the system calculates the level of density according to Table 2. and update the time β of traffic signal on the basis of traffic density. further, undergoes to traffic management algorithm discussed in Figure 3.

Algorithm:

Part(I) When no emergency vehicle detected

if (Traffic Density == high)      if (Rush Interval==Yes)          Time= ((α ex sinθ) + β) + γ      else

         Time = (α ex sinθ) + (cosθ * γ) + β else 

       if (Rush Interval==Yes)            Time= (α ex sinθ) + γ        else 

           Time= α 

Part (II) When RFID tags detect emergency vehicle

           While (vehicle Exits)               Time != 0  

Figure 3. Traffic Management Algorithm 

Where α is regular prefixed time given to a specific roadside, θ=90, x=0, β is extra time added in case of traffic congestion and γ is extra time added when there is rush interval near to approach.

Moreover, if the emergency vehicle is detected, the system stops its normal operation and immediately turns the respective signal green and it remains green until that particular vehicle passes to that intersection. In addition to this, if the fire is detected on the road, the microcontroller intimates to the respective local server through which it goes to the centralized server and then this information goes to the respective department through a mobile application. The flow, how the system calculates signal time, is presented in Figure 4.

 

Figure 4. Flow Chart of Traffic Management System

C. Application and Actuation Layer
In this layer, there are two types of information delivered i) duration of a green signal from node to traffic signal and ii) daily, weekly, monthly and yearly reports to the administration of smart traffic management system through the web application from a centralized server. First of all, the system calculates rush interval by using Regression Tree algorithm on the data saved at the local server and updates this report to the centralized server on the daily basis (after 24 hours). The rush interval is the time span of thirty minutes. This report is then displayed on the web application which is linked to a centralized server which is for the administration of smart traffic management system, that shows daily, weekly, monthly and yearly graphs of rush intervals for roads. This graphical information is fruitful for the future road planning and resource management.

Secondly in the actuation module, whenever the rush interval is identified, the local server intimates to the respective microcontroller along with the road id. After receiving the rush interval intimation, the decision-making module updates the duration of the green signal to the respective traffic signal.

In this modern era, where time is money and wastage of time are not affordable, there is a need to know the traffic condition on the particular road prior to travel on that road by using mobile application. Moreover, this system is also capable of managing emergency situations like if the smoke and fire are detected on the road. In case of fire on the road, which is detected by flame sensors and extensive smoke through smoke sensors, the system intimates to the nearby relevant department through a mobile application for further actions.

RESULTS AND DISCUSSION
A prototype was developed to demonstrate the applicability of our proposed system. Several experiments on real traffic data were carried out to evaluate the efficiency of the proposed algorithm. The traffic density was monitored and calculated by vehicle detection as shown in Figure 5. As soon as the traffic density crosses the specified threshold on a road, the system stopped the normal operation and kept the green light on till the situation on the road became normal. The real-time data was also being sent to the local and central server as well.

 

Figure 5. Vehicles Detection

Besides this, a web interface was also developed for the authorities to show them the statistics of traffic on the roads so that they could make real-time and future decisions as discussed in section III. Figure 6 shows the statistical traffic data i.e. number of vehicles passed in a particular time span at a particular road. The bar graph is representing real-time traffic data. Different bar graphs based on historical and real-time data are being drawn in this application which is helpful for traffic department and other related authorities for i) managing traffic congestions on roads ii) and future planning. 

 

Figure 6. Statistical data on traffic

CONCLUSION
This research presents an effective solution for rapid growth of traffic flow particularly in big cities which is increasing day by day and traditional systems have some limitations as they fail to manage current traffic effectively. Keeping in view the state of the art approach for traffic management systems, a smart traffic management system is proposed to control road traffic situations more efficiently and effectively. It changes the signal timing intelligently according to traffic density on the particular roadside and regulates traffic flow by communicating with local server more effectively than ever before. The decentralized approach makes it optimized and effective as the system works even if a local server or centralized server has crashed. The centralized server communicates the nearest rescue department in case of an emergency situation which provides timely human safety.  Moreover, a user can ask about future traffic level at particular road hence avoiding wastage of time in traffic jams. The system also provides useful information to higher authorities that can be used in road planning which helps in optimal usage of resources.

                 
