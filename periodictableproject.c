#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
void InsertAtBeginning(char value[100]);
void InsertAtEnd(char value[100]);
void InsertAtPosition(char value[100],int position);
void RemoveAtBeginning();
void RemoveAtEnd();
void RemoveAtPosition(int position);
void display();
int CheckEmpty();
struct Node{
 char data[100];
 struct Node *next;
}* head=NULL;
int main()
{
printf("\t\tWELCOME TO MODERN PERIODIC TABLE PROJECT\n");
int n;
printf("\t\t1.PRESS 1 FOR SIGNUP\n\t\t2.PRESS 2 FOR SIGNIN\n\t\t3.PRESS 3 FOR EXIT\n");
    while(1){

    printf("\n\t\tENTER YOUR CHOICE: ");
    scanf("%d",&n);

    switch(n){
        case 1:signup();
               break;
        case 2:signin();
               break;
        case 3:exit(1);
    }
    }
    return 0;
}
void signup()
{
	FILE *fp;
    fp=fopen("detail.txt","a");
    char user[10],pass[10];
    printf("\t\tENTER USERNAME: ");
    scanf("%s",user);
    printf("\t\tENTER PASSWORD: ");
    scanf("%s",pass);
    fprintf(fp,"%s\t%s\n",user,pass);
    fclose(fp);
}
void signin()
{
	system("cls");
	char user[10],pass[10];
    char fuser[10],fpass[10];
    int f,i=0;
    char ch;
    printf("\t\tENTER USERNAME: ");
    scanf("%s",user);
    printf("\t\tENTER PASSWORD(should be maximum of 10 characters): ");
    //scanf("%s",pass);
    while((ch=getch())!=13)
	{
	pass[i]=ch;
	printf("*");
	i++;
	}
	pass[i]='\0';
	FILE *fp;
    fp=fopen("detail.txt","r");
	while((fscanf(fp,"%s\t%s\n",fuser,fpass))!=-1)
    {
		if(strcmp(user,fuser)==0 && strcmp(pass,fpass)==0)
    	{
		f=1;
    	break;
    }
}
    if(f==1){
    	printf("\n\t\tloading\n");
	for(i=0;i<3;i++)
	delay(1);
    printf("\n\t\tWelcome %s\n",user);
	home();
	}
    else
    printf("\n\t\tInvalid Username or Password\n");
    fclose(fp);
}
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
// FUNCTION FOR HOME PAGE
void home()
{
   printf("\n\t\t                           WELCOME TO EXOPLORE MODERN PEROIDIC TABLE\n");
	printf("\n\t\t1.PRESS 1 FOR UPDATING THE PERIODIC TABLE\n\t\t2.PRESS 2 FOR SEARCHING CHEMICAL PROPERITES BY ATOMIC NUMBER\n\t\t3.PRESS 3 FOR SEARCHING HEALTH EFFECTS of ELEMENTS\n\n\tPRESS 4 TO EXIT \n");
	while(1)
	{
		int c;
		printf("\n\t\tENTER YOUR CHOICE: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:update();
					break;
			case 2:atomic();
					break;
			case 3: htheffects();
			case 4:exit(1);
                    break;
			default :
			    {

                printf("INVALID INPUT");
			    break;
			    }
		}
	}
}
//UPDATE FUNCTION
int update()
{
 int choice,n;
 char value[100];


 do{
         printf("\nENTER YOUR CHOICE:\n1-Insert an element\n2-Remove an element\n3-Display an element\n 4- Go back to home page\n");
         scanf("%d",&choice);
         switch(choice)
         {
           case 1:
           {
             int x;
             printf("Enter\n1-Insert at Beginning\n2-Insert at End\n3-Insert at Position\n");
             scanf("%d",&x);
             printf("Enter element,atomic number and symbol to be Inserted\n");
             scanf("%s",&value);
             switch(x)
             {
                case 1:
                {
                 InsertAtBeginning(value);
                  break;
                }
                case 2:
                {
                  InsertAtEnd(value);
                   break;
                  }
                case 3:
                {
                   int position;
                   printf("Enter position to insert a value(counted from 0)\n");
                   scanf("%d",&position);
                   InsertAtPosition(value,position);
                    break;
                 }
                 default :
                  {
                     printf("Enter Valid Choice\n");
                     break;
                   }
              }

              break;
           }

    case 2:
    {
      int x;
      printf("Enter\n1-Delete at Beginning\n2-Delete At End\n3-Delete at Position\n");
      scanf("%d",&x);
      switch(x)
      {
        case 1:
        {
         RemoveAtBeginning();
         break;
        }
        case 2:
        {
         RemoveAtEnd();
         break;
        }
        case 3:
        {
         int position;
         printf("Enter position to be removed starting from 1\n");
         scanf("%d",&position);
         RemoveAtPosition(position);
         break;
        }
        default :
        {
         printf("Enter Valid Choice\n");
         break;
        }
      }
     break;
    }
    case 3:
    {
     display();
     break;
    }
    case 4:
        {
            home();
            break;
        }
    default:
    {
     printf("Enter Valid Choice\n");
     break;
    }
 }
 printf("Enter 1 to continue else any letter\n");
 fflush(stdin);
 scanf("%d",&n);
 printf("\n");
 }while(n==1);

}
//FUNCTION TO INSERT AT BEGINNING
void InsertAtBeginning(char value[100]){
   struct Node *newNumber;
   newNumber = (struct Node*)malloc(sizeof(struct Node));
   strcpy(newNumber->data,value);
   if(head == NULL)
   {
      newNumber->next = NULL;
      head = newNumber;
   }
   else
   {
      newNumber->next = head;
      head = newNumber;
   }
   printf("Given Element %s is inserted at beginning Successfully\n",value);

}
//FUNCTION TO INSERT AT END
void InsertAtEnd(char value[100]){
   struct Node *newNumber;
   newNumber = (struct Node*)malloc(sizeof(struct Node));
   strcpy(newNumber->data,value);
   newNumber->next=NULL;
 if(head==NULL)
 {
  head=newNumber;
 }
 else
 {
  struct Node *temp;
  temp=head;
  while(temp->next!=NULL)
  {
   temp=temp->next;
  }
  temp->next=newNumber;
 }

}
//FUNCTION TO INSERT AT GIVEN POSITION
void InsertAtPosition(char value[100],int position){
   struct Node *newNumber,*temp;
   int count,flag;
   newNumber = (struct Node*)malloc(sizeof(struct Node));
   strcpy(newNumber->data,value);
   temp=head;
   flag=CheckEmpty();
   if(flag==1)
   {
    int flag1=0;
    count=0;
      while(temp!=NULL)
        {
         if(count==position-1)
          {
        flag1=1;
        newNumber->next=temp->next;
           temp->next=newNumber;
       }
       else
    {
        temp=temp->next;

       }
       count++;
          }
            if(flag1==0)
            {
        printf("Entered Position Not available\n");
            }
      else
      {
       printf("Given Name %s is inserted at position %d successfully\n",value,position);
      }
     }
     else
     {
      printf("List is Empty\n");
     }
}
//FUNCTION TO REMOVE ELEMENTS FROM BEGINNING
void RemoveAtBeginning(){
 int flag=CheckEmpty();
 if(flag==1)
 {
  struct Node *temp;
  temp=head;
  if(temp->next==NULL)
  {
   head=NULL;
   free(temp);
  }
  else{
   head=temp->next;
         free(temp);
  }
     printf("Deleted Successfully\n");
 }
 else
 {
  printf("List is Empty\n");
 }
}
//FUNCTION TO REMOVE ELEMENTS FROM END
void RemoveAtEnd(){
 int flag=CheckEmpty();
 if(flag==1)
 {
  if(head->next==NULL)
  {
   head=NULL;
  }
  else
  {
   struct Node *temp=head,*temp1;
      while(temp->next!=NULL)
      {
        temp1=temp;
        temp=temp->next;
      }
      temp1->next=NULL;
      free(temp);
  }

 }
 else
 {
  printf("List Empty.Try again!\n");
 }
}
//FUNCTION TO REMOVE ELEMENTS FROM GIVEN POSITION
void RemoveAtPosition(int position){
  int flag=CheckEmpty();
 if(flag==1)
 {
  int count=0,flag1=0,i;
  struct Node *temp=head;
   if(position==1)
   {
    head=temp->next;
    free(temp);
    return;
   }
   for(i=0;i<position-2;i++)
   {
        temp=temp->next;
   }
   struct Node *temp1=temp->next;
   temp->next=temp1->next;
   free(temp1);


 }
 else
 {
  printf("List is empty\n");
 }

}
//FUNCTION TO DISPLAY ELEMENTS
void display(){
   char arr[1000] = {"hydrogen->1->H \nhelium->2->He\n lithium->3->Li \nberrylium->4->Be\n boron->5->B \ncarbon->6->C \nnitrogen->7->N \noxygen->8->O \nflourine->9->F\n neon->10->Ne \nsodium->11->Na \nmagnesium->12->Mg \naluminium->13->Al \nsilicon->14->Si \nphosphorus->15->P \nsulphur->16->S \nchlorine->17->Cl \nargon->18->Ar \npottasium->19->K\n calcium->20->Ca\n" };

     printf("%s",arr);
 int flag=CheckEmpty();
 if(flag==1)
 {
      struct Node *temp;
     temp=head;
      while(temp->next!=NULL)
     {
      printf("%s->",temp->data);
      temp=temp->next;
      }
      printf("%s",temp->data);
        printf("\n");
 }
 else
 {
  printf("No List Available\n");
 }
}

int CheckEmpty()
{
 if(head==NULL)
 return 0;
 else
 return 1;
}
//FUNCTION TO SEARCH CHMEICAL PROPERTIES USING FILE HANDLING
void atomic()
{
	system("cls");
	char ele[10],sy[10],am[10],ae[10];
	int i,at;
	FILE *fp;
	fp=fopen("PERIODIC.txt","r");
	 char fele[100],fsy[100];
    long fat;
    printf("\n\t\tENTER ATOMIC NUMBER: ");
    scanf("%d",&fat);
    for(i=0;i<=300;++i)
    {
    	fscanf(fp,"%s\t%d\t%s\t%s\t%s\n",ele,&at,sy,am,ae);
    	if(fat==at)
    	printf("\n\t\tELEMENT: %s\n\t\tATOMIC NUMBER: %d\n\t\tCHEMICAL SYMBOL: %s\n\t\tATOMIC MASS: %s\n\t\tELECTRONEGATIVITY: %s\n",ele,at,sy,am,ae);

	}
	home();
	fclose(fp);
home();
}
//FUNCTION TO SEARCH HEALTH EFFECTS
void htheffects()
{

char str[40];
printf("enter the element to be searched:");
scanf("%s",str);
if(strcmp(str,"H")==0|| strcmp(str,"HYDROGEN")==0)
printf("High concentrations of this gas can cause an oxygen-deficient environment. Individuals breathing such an atmosphere may experience symptoms which include headaches, ringing in ears, dizziness, drowsiness, unconsciousness of all the senses. The skin of a victim may have a blue color. Under some circumstances, death may occur.");
if(strcmp(str,"He")==0|| strcmp(str,"HELIUM")==0)
printf("The substance can be absorbed into the body by inhalation. Inhalation: High voice. Dizziness. Dullness. Headache. Suffocation. Skin: on contact with liquid: frostbite. On loss of containment this gas can cause suffocation by lowering the oxygen content of the air in confined areas. Check oxygen content before entering area.");
if(strcmp(str,"Li")==0|| strcmp(str,"LITHIUM")==0)
printf("Burning sensation. Cough. Laboured breathing. Shortness of breath. Sore throat. Symptoms may be delayed. Skin: Redness. Skin burns. Pain. Blisters.");
if(strcmp(str,"Be")==0|| strcmp(str,"BERYILLIUM")==0)
printf("The most commonly known effect of beryllium is called berylliosis, a dangerous and persistent lung disorder that can also damage other organs, such as the heart. In about 20% of all cases people die of this disease.People that have weakened immune systems are most susceptible to this disease.");
if(strcmp(str,"B")==0|| strcmp(str,"BORON")==0)
printf("When humans consume large amounts of boron-containing food, the boron concentrations in their bodies may rise to levels that can cause health problems. Boron can infect the stomach, liver, kidneys and brains and can eventually lead to death.");
if(strcmp(str,"C")==0|| strcmp(str,"CARBON")==0)
printf("Elemental carbon is of very low toxicity.Chronic inhalation exposure to carbon black may result in temporary or permanent damage to lungs and heart.");
if(strcmp(str,"N")==0|| strcmp(str,"NITROGEN")==0)
printf("Reactions with haemoglobin in blood, causing the oxygen carrying capacity of the blood to decrease (nitrite),Decreased functioning of the thyroid gland (nitrate),Vitamin A shortages (nitrate)");
if(strcmp(str,"0")==0|| strcmp(str,"OXYGEN")==0)
printf("Oxygen is essential for all forms of life since it is a constituent of DNA and almost all other biologically important compounds. Is it even more drammatically essential, in that animals must have minute by minute supply of the gas in order to survive.");
if(strcmp(str,"F")==0|| strcmp(str,"FLUORINE")==0)
printf("Fluorine is essential for the maintenance of solidity of our bones. Fluorine can also protect us from dental decay, if it is applied through toothpaste twice a day. If fluorine is absorbed too frequently, it can cause teeth decay, osteoporosis and harm to kidneys, bones, nerves and muscles.");
if(strcmp(str,"Ne")==0|| strcmp(str,"NEON")==0)
printf("This gas is inert and is classified as a simple asphyxiant. Inhalation in excessive concentrations can result in dizziness, nausea, vomiting, loss of consciousness, and death. Death may result from errors in judgment, confusion, or loss of consciousness which prevent self-rescue.");
if(strcmp(str,"Na")==0|| strcmp(str,"SODIUM")==0)
printf("Contact of sodium with water, including perspiration causes the formation of sodium hydroxide fumes, which are highly irritating to skin, eyes, nose and throat. This may cause sneezing and coughing.");
if(strcmp(str,"Mg")==0|| strcmp(str,"MAGNESIUM")==0)
printf("ow toxicity & not considered to be hazardous to health. Inhalation: dust may irritate mucous membranes or upper respiratory tract,the body deals very effectively with this element, taking it form food when it can, and recycling what we already have when it cannot.");
if(strcmp(str,"Al")==0|| strcmp(str,"ALUMINIUM")==0)
printf("Aluminum is a risk in certain working environments, such as mines, where it can be found in water. People that work in factories where aluminum is applied during production processes may endure lung problems when they breathe in aluminum dust.");
if(strcmp(str,"Si")==0|| strcmp(str,"SILICON")==0)
printf("Silicon concentrates in no particular organ of the body but is found mainly in in connective tissues and skin. Silicon is non-toxic as the element and in all its natural forms, nameli silica and silicates, which are the most abundant.");
if(strcmp(str,"P")==0|| strcmp(str,"PHOSPHORUS")==0)
printf("Phosphorus can be found in the environment most commonly as phosphates. Phosphates are important substances in the human body, because they are a part of DNA materials and they take part in energy distribution. Phosphates can also be found commonly in plants.");
if(strcmp(str,"S")==0|| strcmp(str,"SULPHUR")==0)
printf("All living things need sulphur. It is especially important for humans because it is part of the amino acid methionine, which is an absolute dietary requirement for us.The average person takes in around 900 mg of sulphur per day, mainly in the form of protein.");
if(strcmp(str,"Cl")==0|| strcmp(str,"CHLORINE")==0)
printf("Chlorine enters the body breathed in with contaminated air or when consumed with contaminated food or water. It does not remain in the body, due to its reactivity. Effects of chlorine on human health depend on how the amount of chlorine that is present, and the length and frequency of exposure.");
if(strcmp(str,"Ar")==0|| strcmp(str,"ARGON")==0)
printf("This gas is inert and is classified as a simple asphyxiant. Inhalation in excessive concentrations can result in dizziness, nausea, vomiting, loss of consciousness, and death.");
if(strcmp(str,"K")==0|| strcmp(str,"POTASSIUM")==0)
printf("Potassium can be found in vegetables, fruit, potatoes, meat, bread, milk and nuts. It plays an important role in the physical fluid system of humans and it assists nerve functions. Potassium, as the ion K+, concentrate inside cells, and 95% of the body's potassium is so located.");
if(strcmp(str,"Ca")==0|| strcmp(str,"CALCIUM")==0)
printf("A lack of calcium is one of the main causes of osteoporosis. Osteoporosis is a disease in which the bones become extremely porous, are subject to fracture, and heal slowly, occurring especially in women following menopause and often leading to curvature of the spine from vertebral collapse.");
home();
    }


