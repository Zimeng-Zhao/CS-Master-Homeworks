
#ID:20012231
#Name:Zimeng Zhao
#Date:04-18-2023

rm(list=ls())

#Load the data
filename<-file.choose()
mydata<-read.csv(filename, na.strings=c("?"))
mydata[is.na(mydata)]<-0
View(mydata)
summary(mydata)

#Setting the seed of the random number generator to a specific value ensures that the same sequence of random numbers will be generated each time the code is run, making the results reproducible. 
set.seed(123)

#Assigns the value of 1 to the "predata" column of the "mydata" data frame for any rows where the "diagnosis" column has the value "M".
mydata[mydata$diagnosis=="M","Output"]<- 1 
mydata[mydata$diagnosis=="B","Output"]<- 0 

#Creates a new data frame called "BC_conti" by selecting all columns of the "mydata" data frame except for the first and second columns.
predata <- mydata[,c(-1, -2)]
summary(predata)

#When a data frame is attached, the column names of the data frame become variables that can be directly accessed without having to use the "$" operator. 
attach(predata)
#predata[is.na(predata)]<-0

#Randomly sample a subset of rows from a data frame called "predata" to be used as a test set and a train set.
index<-sort(sample(nrow(predata),round(.3*nrow(predata))))
training<-predata[-index,]
testing<-predata[index,]

#ANN methodology
#install.packages("neuralnet")
library("neuralnet")

#Train the neural network with five (5) nodes in the hidden layer
#"Output~." specifies the formula for the neural network model. In this case, "Output" is the dependent variable (i.e., the variable we want to predict), and the "~." notation indicates that all other variables in the "predata" data frame should be used as independent variables in the model.
#"hidden=5" specifies that the neural network should have one hidden layer with five nodes.
#"threshold=0.01" specifies the threshold value for the partial derivatives of the error function. This threshold determines the stopping criteria for the neural network training algorithm. 
nnm<- neuralnet(Output~., training, hidden=5, threshold = 0.01)
print(nnm)

prediction <-predict(nnm , testing)
print(prediction)
pred_cat <- ifelse(prediction<0.5,0,1)
table(Actual = testing$Output, Prediction = pred_cat)

wrong<- (testing$Output!=pred_cat)
error_rate<-sum(wrong)/length(wrong)
error_rate

successrate <- 1 - error_rate
successrate
