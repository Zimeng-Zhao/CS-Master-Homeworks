
#  Project    : CS513
#  Purpose    : hw4 
#  First Name : Zimeng
#  Last Name  : Zhao
#  Id			    : 20012231
#  Date       : 03/18/2023

# clearing object environment
rm(list=ls())

# get working directory
getwd()

# set working directory
setwd("C:\\Users\\65181\\Desktop\\513")

# make sure of working directory
getwd()

# import Naive Bayes Classifier and class package
library(e1071)
library(class)

# load data file
mydata <- read.csv('breast-cancer-wisconsin.csv',na.string="?")

# view data file
View(mydata)

# delete the rows with missing value
mydata_clean<-na.omit(mydata)

# converting the Class into type factor
mydata$Class<- factor(mydata$Class , levels = c("2","4") , labels = c("Benign","Malignant"))
is.factor(mydata$Class)

newdata<- mydata[2:11]

# sample size: 70% 
samp <- floor(0.70 * nrow(newdata))

#Set the seed 
set.seed(100)
train_ind <- sample(seq_len(nrow(newdata)), size = samp)

#Loading 70% Breast cancer record in training dataset
training <- newdata[train_ind, ]

#Loading 30% Breast cancer in test dataset
test <- newdata[-train_ind, ]

#Implementing NaiveBayes
model_naive<- naiveBayes(Class ~ ., data = training)

#Predicting target class for the Validation set
predict_naive <- predict(model_naive, test)

conf_matrix <- table(predict_nb=predict_naive,class=test$Class)
print(conf_matrix)



#Output of Naive Bayes Classifier
accuracy <- function(x){sum(diag(x)/(sum(rowSums(x)))) * 100}
accuracy(conf_matrix)



