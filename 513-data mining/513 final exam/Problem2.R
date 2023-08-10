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
Data$Abs_cat <- factor(Data$Abs_cat, labels = c("Abs_high", "Abs_med", "Abs_low"))
View(Data$Abs_cat)
is.factor(Data$Abs_cat)

#get same data
set.seed(123)

#test data & training data
idx<-seq(1,nrow(Data),by=4)
idx
training<-Data[-idx,]
nrow(training)
test<-Data[idx,]
nrow(test)


#Random Forest
library(randomForest)

fit <- randomForest( Abs_cat~., data=training, importance=TRUE, ntree=1000)

importance(fit)
varImpPlot(fit)
dev.off()
RPrediction <- predict(fit, test)
a<-table(actual=test$Abs_cat,RPrediction)
a

#Error rate
wrong<- (test$Attrition!=RPrediction )
error_rate<-sum(wrong)/length(wrong)
error_rate 

#Accuracy
Accuracy <-(sum(diag(a))/(sum(rowSums(a)))*100) 
Accuracy

#Precision of your classification for Abs_cat=Abs_High
Precision = a[1,1] / (a[1,1] + a[2,1])
Precision