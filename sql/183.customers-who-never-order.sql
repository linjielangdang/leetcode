select Name from Customers as a left join Orders as b on a.Id = b.CustomerId where b.Id is NULL;
