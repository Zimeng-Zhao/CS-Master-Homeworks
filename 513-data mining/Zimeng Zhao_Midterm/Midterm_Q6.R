install.packages("caTools")

library(e1071)
library(caTools)
library(class)

# read the csv file
rm(list=ls())
setwd("C:\\Users\\65181\\Desktop\\513")
dataset <- read.csv("CS513_targeting_num.csv", header = TRUE, stringsAsFactors = FALSE, na.strings = "?")

# delete the rows with missing value
iris <- na.omit(dataset)
data_new2 <- iris                                    # Duplicate data frame
data_new2$Gender <- as.numeric(as.factor(data_new2$Gender))
data_new2 
# Splitting data into train
# and test data
split <- sample.split(data_new2, SplitRatio = 0.7)
train_cl <- subset(data_new2, split == "TRUE")
View(train_cl)
test_cl <- subset(data_new2, split == "FALSE")
View(test_cl)
# Feature Scaling
train_scale <- scale(train_cl[, 1:4])
test_scale <- scale(test_cl[, 1:4])

# Fitting KNN Model 
# to training dataset
classifier_knn <- knn(train = train_scale, test = test_scale, cl = train_cl$Purchase, k = 3)
conf_matrix <- table(classifier_knn, test_cl$Purchase)
conf_matrix

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
