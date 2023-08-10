#  Company    : Stevens 
#  Project    : CS513
#  Purpose    : hw3 
#  First Name : Zimeng
#  Last Name  : Zhao
#  Id			    : 20012231
#  Date       : 02/27/2023

# clearing object environment
rm(list=ls())

# get working directory
getwd()

# set working directory
setwd("C:\\Users\\65181\\Desktop\\513")

#load data file
mydata <- read.csv('breast-cancer-wisconsin.csv',na.string="?")

#view data file
View(mydata)

# delete the rows with missing value
mydata_clean<-na.omit(mydata)

# use 30% data for test
recordRange <- seq(from = 1, to = nrow(mydata_clean), by = 4)
test <- mydata_clean[recordRange, ]

# use 70% data to training
training <- mydata_clean[-recordRange, ]

# importing "class" package
library(class);

# k = 3
predict3 <- knn(training[ , -4], test[ , -4], training[ , 4], k = 3)
table(Predict = predict3, Actual = test[ , 4])

# k = 5
predict5 <- knn(training[ , -4], test[ , -4], training[ , 4], k = 5)
table(Predict = predict5, Actual = test[ , 4])

# k = 10
predict10 <- knn(training[ , -4], test[ , -4], training[ , 4], k = 10)
table(Predict = predict10, Actual = test[ , 4])

# clearing object environment
rm(list=ls())

