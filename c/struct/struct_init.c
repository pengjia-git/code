struct uvc_processing_unit_descriptor {
  unsigned char  bLength;
  unsigned char  bDescriptorType;
  unsigned char  bDescriptorSubType;
  unsigned char  bUnitID;
  unsigned char  bSourceID;
  short  wMaxMultiplier;
  unsigned char  bControlSize;
  unsigned char  bmControls[2];
  unsigned char  iProcessing;
} __attribute__((__packed__));


int main()
{
  struct uvc_processing_unit_descriptor a={
    .bLength=1,
    .bDescriptorSubType=3,
    .bmControls={1,2},
    .iProcessing=1
  };
  return 0;
}
