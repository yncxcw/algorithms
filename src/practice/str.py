class Solution(object):
    
    def convertoToint(self,version):
        vect=[]
        if "." in version:
            versions=version.split(".")
            vect    =map(lambda x:int(x),versions)
        else:
            vect.append(int(version))
        return vect
        
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        vect1=self.convertoToint(version1)
        vect2=self.convertoToint(version2)
       
        len1 =len(vect1)
        len2 =len(vect2)
        if len1 > len2:
            for i in range(0,len1-len2):
                vect2.append(0)
        elif len2 > len1:
            for i in range(0,len2-len1):
                vect1.append(0)
            
        flen=len(vect1)       
        print vect1
        print vect2 
        l=0
        while l < flen:
            print "index",l
            print vect1[l],vect2[l]
            if vect1[l] > vect2[l]:
                return 1
            elif vect1[l] < vect2[l]:
                return -1
            else:
                l=l+1
        return 0
      
slo=Solution()
print slo. compareVersion("1","1.1")
