#  Course     : CS513
#  Name       : Zimeng Zhao
#  Id			    : 20012231

# clearing object environment
rm(list=ls())

# get working directory
getwd()

# set working directory
setwd("C:\\Users\\65181\\Desktop\\513")

# load data file
mydata <- read.csv('CS513_targeting_cat_full.csv',na.string="?")

# view data file
View(mydata)

# delete the rows with missing value
mydata_clean<-na.omit(mydata)

# import Naive Bayes Classifier and class package
library(e1071)
library(class)


newdata<- mydata[2:6]

# sample size: 30% 
samp <- floor(0.30 * nrow(newdata))

# set the seed 
set.seed(123)
train_ind <- sample(seq_len(nrow(newdata)), size = samp)

# loading 30% purchase record in training dataset
training <- newdata[train_ind, ]

#Loading 70% purchase record in test dataset
test <- newdata[-train_ind, ]

#Implementing NaiveBayes
model_naive<- naiveBayes(Purchase ~ ., data = training)

#Predicting target class for the Validation set
predict_naive <- predict(model_naive, test)

conf_matrix <- table(predict_nb=predict_naive,class=test$Purchase)
print(conf_matrix)

# Extract values from the confusion matrix
tp <- conf_matrix[2, 2] # True positives
fp <- conf_matrix[1, 2] # False positives
tn <- conf_matrix[1, 1] # True negatives
fn <- conf_matrix[2, 1] # False negatives

# Calculate accuracy
accuracy <- (tp + tn) / (tp + fp + tn + fn)
accuracy

# Calculate precision
precision <- tp / (tp + fp)
precision

# Calculate specificity
specificity <- tn / (tn + fp)
specificity

# Calculate recall
recall <- tp / (tp + fn)
recall

# Calculate F1-score
f1 <- 2 * precision * recall / (precision + recall)
f1