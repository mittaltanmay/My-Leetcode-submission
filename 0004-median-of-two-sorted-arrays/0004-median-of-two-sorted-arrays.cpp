class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int s=n1+n2;
        int ind1=(s/2)-1;
        double el1,el2;
        int ind2=s/2;
        int i=0,j=0,k=0;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<=nums2[j])
            {
                if(k==ind1) el1=nums1[i];
                else if(k==ind2) el2=nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                if(k==ind1) el1=nums2[j];
                else if(k==ind2) el2=nums2[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            if(k==ind1) el1=nums1[i];
            else if(k==ind2) el2=nums1[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            if(k==ind1) el1=nums2[j];
            else if(k==ind2) el2=nums2[j];
            j++;
            k++;
        }
        if(s & 1) return el2;
        else return (el1+el2)/2.0;
    }
};