# C++ Project - Car Rental System  <img height="52" width="52" src="https://cdn-icons.flaticon.com/png/512/3393/premium/3393345.png?token=exp=1656581694~hmac=a1101edf3698d3a1846bbbad95bbe400">

     The purpose of this project is to streamline how the car rental applications work.
##### **The following app has 3 main options:**<br/>
     1. Administrator option
     2. Company registration option
     3. Client option


### <img height="52" width="52" src="https://cdn-icons-png.flaticon.com/512/684/684930.png"> Brief description:

#### <img height="52" width="52" src="https://cdn-icons-png.flaticon.com/512/2082/2082875.png"> Administrator:
     The administrator part can view the list of companies registered. Addtionally, he can warn the companies if the
     reviews are worse and he can even remove them (after several warnings) if the clients are constantly submitting
     negative reviews. Also, the admin can change the password for this "branch" of the app. To be mentioned is the 
     fact that if one person tries to enter the admin password and in case it is introduced 3 times incorrectly,
     the user will be redirected to the main page.
     
#### <img height="52" width="52" src="https://cdn-icons.flaticon.com/png/512/4745/premium/4745657.png?token=exp=1656583339~hmac=2a294fd35ec28b89590d023772198a1c"> Company registration:
     The company registration option is dedicated to the companies. Each location has its manager and list of cars. 
     Clients are able to rent a car from a location and drop it to another location should he wish to.
>After selecting the first option, the user should introduce the firm name, country, city, the number of the cars, 
phone number etc. Afterwards, the user should introduce the specifications for each car, from make, color to number 
of seats, doors and payment details. 
After completing all the steps, the firm will be registered and available in the firms list for clients.
<br/>

#### <img height="52" width="52" src="https://cdn-icons-png.flaticon.com/512/6009/6009864.png"> Client:
     The client side includes gathering of personal data (firstname, lastname, driving license details etc. ) - because
     the client must have an account and must be logged in in order to rent or drop cars. Furthermore, the client 
     has to introduce the location from where he wants to rent the car and where he wants to drop it. Following this 
     process, an immediate response will be given regarding the availability of the car and the steps to be followed in
     the case of non-availability of the car.
>During the rental process, the user should select one of the companies and the car he would like to rent. <br/>
Another option is making use of the current rented cars. Thus, the client may take a look around the rented cars
at the moment. The customer may also drop a car or more. 

<br/>

## How to run it <img height="52" width="52" src = "https://user-images.githubusercontent.com/92999481/166147080-e3baac9b-3d24-439d-aa7b-4eec7a59edc2.png">

**```[1]```** All files must be in the **same** folder. 
<br>
<br>
**```[2]```**
- **If you are using Microsoft Visual Studio IDE (recommended way)** you can open the project automatically from here, in the ```Code``` section, press ```Open with Visual Studio``` and then search for **```proiect_cpp.sln```** (main file). Or you can downlad this repository and open it with ```Microsoft Visual Studio IDE```. Or you can clone it using ```git clone https://github.com/Emanuel181/Car-Rental-System.git```.

- **If you are using other sotfware** you should search for ```Source.c``` by following the path ```Proiect_Programare/Project1/Source.c``` and you will probably need to manage the extra headers files defined by me by yourself in order to run the project. It was created in ```Microsoft Visual Studio IDE``` so opening it with another IDE or text editor may require extra work to set all files correctly. The most simple and efficient way is to use **```Microsoft Visual Studio IDE```**.

<hr>
<br>
<br>

## Core aspects <img height="52" width="52" src = "https://user-images.githubusercontent.com/92999481/166150746-71e05c9b-3ef1-4179-b659-dbfcf0629fea.png">
- [x] Loading screen
- [x] The posibility to create accounts
- [x] Validations
- [x] A very complex project
- [x] Databases for clients, accounts, branches, rented cars, cars stored as CSV
- [x] The posibility to add new firms
- [x] The posibility to add a review for a firm
- [x] The posibility to add rent cars
- [x] The posibility to change admin password
- [x] We use an encryption algorithm to hide passwords
- [x] Used OOP paradigm
- [x] Team project (2 persons)

<br/><br/><hr/>
### <img height="52" width="52" src="https://cdn-icons-png.flaticon.com/512/5361/5361007.png"> Demo - How it works
#### ***Loading screen***:<br/><br/>
![Capture1](https://user-images.githubusercontent.com/92999481/176640926-1e933b16-b8d8-456b-a12d-1a3a4a3e3868.PNG)
 
#### ***Menus***:<br/><br/>
##### *Main Menu:* <br/>
![image](https://user-images.githubusercontent.com/92984942/176542706-4f157ed1-3dee-4957-a495-e0ffe55e0827.png)
<br/><br/>

##### *Admin menu:* <br/>
![image](https://user-images.githubusercontent.com/92984942/176543558-5baea659-ba42-49c6-8c45-ecb749ba2fb3.png)
  1. Adding warnings/observations <br/>
  ![Capture2](https://user-images.githubusercontent.com/92999481/176640211-e13cbdd7-4324-4195-bf05-746318ae59fa.PNG) <br/>
  ![Capture3](https://user-images.githubusercontent.com/92999481/176640556-11beb6ec-d898-4252-a453-390cb9040bd3.PNG)
<br/><br/>

##### *Company registration menu:* <br/>
![image](https://user-images.githubusercontent.com/92984942/176543736-b1ba8a79-fd5d-4671-9738-c92fd7ca8244.png)
<br/><br/>

##### *Firm registration process:* <br/>
 1. Firm details <br/>
 ![img](https://user-images.githubusercontent.com/92984942/176547285-30b842f1-b6ed-4372-adbd-96ef91305231.png)
<br/>

 2. Car details <br/>
 ![image](https://user-images.githubusercontent.com/92984942/176545380-4976d1ef-d0a4-4948-a313-ad219ef2bcdf.png)
<br/>

##### *Client menu:* <br/>
![image](https://user-images.githubusercontent.com/92984942/176546010-b426156d-5fb2-4213-b6a5-e0835e91b78e.png)
 1. Cars rented by a person <br/><br/>
 ![Capture5](https://user-images.githubusercontent.com/92999481/176646456-09199e35-e960-40a6-b925-b99f4c755572.PNG)
 ![Capture6](https://user-images.githubusercontent.com/92999481/176646489-f8ee9166-cb20-437d-a7fd-887dcd606a7c.PNG)
 ![Capture7](https://user-images.githubusercontent.com/92999481/176646513-dc4938d4-99b5-41e9-a9ba-b75d1d1cc369.PNG)
 ![Capture4](https://user-images.githubusercontent.com/92999481/176646533-f74ac629-261e-4790-a164-5ef73ab00b5c.PNG)

<br/><br/>

##### *Account menu:* <br/>
![image](https://user-images.githubusercontent.com/92984942/176546310-b973fc68-60d4-4cdc-aca6-05e66a0b096f.png)
<br/><br/>

##### *List of companies:* <br/>
![image](https://user-images.githubusercontent.com/92984942/176601451-34e99aaf-36c6-4e09-965b-c81dc62f72f9.png)
<br/><br/>

##### *Current car(s):* <br/>
![image](https://user-images.githubusercontent.com/92984942/176601737-26963ad7-84f2-49ec-96f0-2049b6fae2c8.png)
<br/><br/>

##### *Confirmation message in case a car has been dropped:* <br/>
![image](https://user-images.githubusercontent.com/92984942/176601851-9a81972b-ecab-4422-ab5e-59203b1419ce.png)
<br/><br/>
<br>
<br>

[![](https://tokei.rs/b1/github/AlexandruAndrita/Car-Rental-System?category=lines)](https://github.com/XAMPPRocky/tokei_rs).


![image](https://user-images.githubusercontent.com/92999481/169172665-3f6d4261-fbe1-49f9-a9a7-93ffd468e8a4.png)
<br>
<br>
<br>
🌐: https://www.uvt.ro/ro/

🌐: https://www.info.uvt.ro/en/
