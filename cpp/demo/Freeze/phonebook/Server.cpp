// **********************************************************************
//
// Copyright (c) 2001
// MutableRealms, Inc.
// Huntsville, AL, USA
//
// All Rights Reserved
//
// **********************************************************************

#include <Evictor.h>

using namespace Ice;
using namespace std;

int
run(int argc, char* argv[], CommunicatorPtr communicator)
{
    ObjectAdapterPtr adapter = communicator->createObjectAdapter("PhoneBookAdapter");
    PhoneBookIPtr phoneBook = new PhoneBookI(adapter);
    adapter->add(phoneBook, "phonebook");
    ServantLocatorPtr evictor = new Evictor(phoneBook);
    adapter->setServantLocator(evictor);
    adapter->activate();
    communicator->waitForShutdown();
    return EXIT_SUCCESS;
}

int
main(int argc, char* argv[])
{
    int status;
    CommunicatorPtr communicator;

    try
    {
	PropertiesPtr properties = createPropertiesFromFile(argc, argv, "config");
	communicator = initializeWithProperties(properties);
	status = run(argc, argv, communicator);
    }
    catch(const LocalException& ex)
    {
	cerr << ex << endl;
	status = EXIT_FAILURE;
    }

    if (communicator)
    {
	try
	{
	    communicator->destroy();
	}
	catch(const LocalException& ex)
	{
	    cerr << ex << endl;
	    status = EXIT_FAILURE;
	}
    }

    return status;
}
