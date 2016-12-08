select b.Id from Weather as a, Weather as b where TO_DAYS(a.Date) = TO_DAYS(b.Date) - 1 and a.Temperature < b.Temperature;

