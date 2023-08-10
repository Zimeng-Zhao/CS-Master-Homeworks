
rm(list=ls())

#Load the data
filename<-file.choose()
mydata<-read.csv(filename, na.strings=c("?"))
View(mydata)
summary(mydata)

# delete the rows with missing value
pharma_data <- na.omit(mydata)

#  Pre-processing, convert categorical columns to numeric for pharma_data
pharma_data <- pharma_data[,-3] # Eliminate the 3rd column for identifier
pharma_data$Patient_Smoker <- ifelse(pharma_data$Patient_Smoker == "YES", 1, 0)
pharma_data$Patient_Rural_Urban <- ifelse(pharma_data$Patient_Rural_Urban == "URBAN", 1, 0)
pharma_data$Patient_mental_condition <- ifelse(pharma_data$Patient_mental_condition == "Stable", 1, 0)
View(pharma_data)

#Define z_score normalization function
pharma_data$Number_of_prev_cond_zscore <- scale(pharma_data$Number_of_prev_cond)
pharma_data$Patient_Age_zscore <- scale(pharma_data$Patient_Age)
pharma_data$Diagnosed_Condition_zscore <- scale(pharma_data$Diagnosed_Condition)
pharma_data$Patient_Body_Mass_Index_zscore <- scale(pharma_data$Patient_Body_Mass_Index)
pharma_data$ID_Patient_Care_Situation_zscore <- scale(pharma_data$ID_Patient_Care_Situation)

#install.packages('e1071', dependencies = TRUE)
library(e1071)
library(class) 

newdata<- pharma_data[2:11]