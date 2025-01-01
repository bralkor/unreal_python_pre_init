#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FPythonAddPreInitModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void RunPreInitScripts() const;
};