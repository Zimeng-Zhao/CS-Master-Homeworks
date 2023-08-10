# Course      : CS 513B
# Name        : Zimeng Zhao
# CWID        : 20012231

rm(list=ls())
install.packages('randomForest')


#Load the data
filename<-file.choose()
Data<-read.csv(filename, na.strings=c("?"))
Data <- na.omit(Data)
View(Data)

#Convert Class Column to Factor
Data$Abs_cat <- factor(Data$Abs_cat)

library(caTools)
library(rpart)
library(rpart.plot)     
library(rattle)           
library(RColorBrewer)
set.seed(123)

#test data & training data
idx<-seq(1,nrow(Data),by=4)
idx
training<-Data[-idx,]
nrow(training)
test<-Data[idx,]
nrow(test)

# Build the CART model
library(rpart)
mytree <- rpart(Abs_cat ~ ., data = training)
rpart.plot(mytree)

# Make predictions on the testing set
predictions <- predict(mytree, test, type = "class")
str(predictions)

# Evaluate the accuracy of the model
#library(caret)
#confusionMatrix(predictions, test$Abs_cat)$overall['Accuracy']

#Confusion Matrix
Matrix<-table(Actual=test$Abs_cat,CART=predictions)
accuracy <- function(x){sum(diag(x)/(sum(colSums(x))))}
accuracy(Matrix)

#Precision
TP <- Matrix["Abs_High","Abs_High"]
FP <- sum(Matrix["Abs_Med","Abs_High"], Matrix["Abs_low","Abs_High"])
precision <- TP / (TP + FP)
precision
CART_wrong<-sum(test$Abs_cat!=predictions)
CART_error_rate<-CART_wrong/length(test$Abs_cat)
CART_error_rate


library(rpart.plot)
?prp()
prp(mytree)


